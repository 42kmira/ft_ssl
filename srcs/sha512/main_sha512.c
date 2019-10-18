/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sha512.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:25:06 by kmira             #+#    #+#             */
/*   Updated: 2019/10/18 15:01:25 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"
#include "main_sha512.h"

#define R_BIT_ROT64E(val, shift) ((val >> shift) | (val << (64 - shift)))
#define RIGHT_BIT_SHIFT64(val, shift) ((val >> shift))

void		fill_chunk_e(char *str, t_1024_chunk *chunk, int final, int *padded)
{
	int				i;
	int				j;
	int				len;
	int				stop;
	t_conveter_e	transmutation_decive;

	len = ft_strlen(str);
	i = -1;
	stop = (final ? 13 : 16);
	while (++i < stop && (i + 1) * 8 < len)
		ft_memcpy(&chunk->block[i], &str[i * 8], 8);
	j = -1;
	transmutation_decive.num = 0;
	while (++j < 8 && str[i * 8 + j] != '\0')
		transmutation_decive.args[j] = str[i * 8 + j];
	if (len < 64 && *padded == 0 && j == 8)
	{
		chunk->block[i] = transmutation_decive.num;
		transmutation_decive.num = 0b10000000;
		i++;
	}
	else if (len < 64 && *padded == 0)
		transmutation_decive.args[j] = 0b10000000;
	*padded = (len < 64 && *padded == 0) ? 1 : 0;
	chunk->block[i] = transmutation_decive.num;
}

static void	compression_function(uint64_t *state, uint64_t *w)
{
	int			i;
	uint64_t	num[6];

	i = -1;
	while (++i < 80)
	{
		num[S1] = (R_BIT_ROT64E(state[H4], 14) ^ (R_BIT_ROT64E(state[H4], 18))
				^ R_BIT_ROT64E(state[H4], 41));
		num[CH] = (state[H4] & state[H5])
				^ ((~state[H4]) & state[H6]);
		num[TEMP1] = state[H7] + num[S1] + num[CH] + g_k[i] + w[i];
		num[S0] = (R_BIT_ROT64E(state[H0], 28) ^ R_BIT_ROT64E(state[H0], 34)
				^ R_BIT_ROT64E(state[H0], 39));
		num[MAJ] = (state[H0] & state[H1]) ^ (state[H0] & state[H2])
				^ (state[H1] & state[H2]);
		num[TEMP2] = num[S0] + num[MAJ];
		state[H7] = state[H6];
		state[H6] = state[H5];
		state[H5] = state[H4];
		state[H4] = state[H3] + num[TEMP1];
		state[H3] = state[H2];
		state[H2] = state[H1];
		state[H1] = state[H0];
		state[H0] = num[TEMP1] + num[TEMP2];
	}
}

static void	extend_function(uint64_t *w)
{
	int			i;
	uint64_t	s1;
	uint64_t	s0;

	i = 16;
	while (i < 80)
	{
		s0 = R_BIT_ROT64E(w[i - 15], 1) ^ R_BIT_ROT64E(w[i - 15], 8)
			^ RIGHT_BIT_SHIFT64(w[i - 15], 7);
		s1 = R_BIT_ROT64E(w[i - 2], 19) ^ R_BIT_ROT64E(w[i - 2], 61)
			^ RIGHT_BIT_SHIFT64(w[i - 2], 6);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
}

static void	one_chunk(t_sha512 *sha512_info)
{
	int			i;
	uint64_t	w[80];
	uint64_t	state[8];

	i = -1;
	ft_bzero(&w, sizeof(w));
	while (++i < 16)
	{
		sha512_info->chunk.block[i] =
		convert_endian_64bits(sha512_info->chunk.block[i]);
		w[i] = sha512_info->chunk.block[i];
	}
	extend_function(w);
	print_we(w);
	i = -1;
	while (++i < 8)
		state[i] = sha512_info->state[i];
	compression_function(state, w);
	i = -1;
	while (++i < 8)
		sha512_info->state[i] = state[i] + sha512_info->state[i];
}

t_string	*crypto_algo_sha512(t_output *output_handle, char *args)
{
	t_sha512	sha512;
	int			padded;
	size_t		bytes_copied;

	padded = 0;
	initialize_sha512(&sha512);
	output_handle->at = 0;
	output_handle->args = args;
	bytes_copied = request_chunk(output_handle, sha512.digest, 128);
	printf("DEST: %s\n", sha512.digest->string);
	while (bytes_copied >= 128 - 16)
	{
		ft_bzero(&sha512.chunk, sizeof(sha512.chunk));
		fill_chunk_e(sha512.digest->string, &sha512.chunk, 0, &padded);
		one_chunk(&sha512);
		make_digest_sha512(sha512.state, sha512.digest);
		bytes_copied = request_chunk(output_handle, sha512.digest, 128);
	}
	ft_bzero(&sha512.chunk, sizeof(sha512.chunk));
	fill_chunk_e(sha512.digest->string, &sha512.chunk, 1, &padded);
	sha512.chunk.block[15] = convert_endian_64bits(output_handle->at * 8);
	one_chunk(&sha512);
	make_digest_sha512(sha512.state, sha512.digest);
	return (sha512.digest);
}
