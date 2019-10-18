/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sha224.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:25:06 by kmira             #+#    #+#             */
/*   Updated: 2019/10/18 15:09:56 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"
#include "main_sha224.h"

#define R_BIT_ROT32(val, shift) ((val >> shift) | (val << (32 - shift)))
#define RIGHT_BIT_SHIFT32(val, shift) ((val >> shift))

static void	make_digest_sha224(uint32_t block[16], t_string *dest)
{
	int			i;
	u_int32_t	num;

	i = 0;
	while (i < 8)
	{
		num = block[7 - i];
		dest->string[(i * 8) + 0] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 1] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 2] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 3] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 4] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 5] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 6] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 7] = g_digits[num % 16];
		i++;
	}
	ft_strnrev(dest->string, dest->length);
}

static void	compression_function(uint32_t *state, uint32_t *w)
{
	int			i;
	uint32_t	num[6];

	i = -1;
	while (++i < 64)
	{
		num[S1] = (R_BIT_ROT32(state[H4], 6) ^ (R_BIT_ROT32(state[H4], 11))
				^ R_BIT_ROT32(state[H4], 25));
		num[CH] = (state[H4] & state[H5])
				^ ((~state[H4]) & state[H6]);
		num[TEMP1] = state[H7] + num[S1] + num[CH] + g_k[i] + w[i];
		num[S0] = (R_BIT_ROT32(state[H0], 2) ^ R_BIT_ROT32(state[H0], 13)
				^ R_BIT_ROT32(state[H0], 22));
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

static void	extend_function(uint32_t *w)
{
	int			i;
	uint32_t	s1;
	uint32_t	s0;

	i = 16;
	while (i < 64)
	{
		s0 = R_BIT_ROT32(w[i - 15], 7) ^ R_BIT_ROT32(w[i - 15], 18)
			^ RIGHT_BIT_SHIFT32(w[i - 15], 3);
		s1 = R_BIT_ROT32(w[i - 2], 17) ^ R_BIT_ROT32(w[i - 2], 19)
			^ RIGHT_BIT_SHIFT32(w[i - 2], 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
}

static void	one_chunk(t_sha224 *sha224_info)
{
	int			i;
	uint32_t	w[64];
	uint32_t	state[8];

	i = -1;
	ft_bzero(&w, sizeof(w));
	while (++i < 16)
	{
		sha224_info->chunk.block[i] =
		convert_endian_32bits(sha224_info->chunk.block[i]);
		w[i] = sha224_info->chunk.block[i];
	}
	extend_function(w);
	i = -1;
	while (++i < 8)
		state[i] = sha224_info->state[i];
	compression_function(state, w);
	i = -1;
	while (++i < 8)
		sha224_info->state[i] = state[i] + sha224_info->state[i];
}

t_string	*crypto_algo_sha224(t_output *output_handle, char *args)
{
	t_sha224	sha224;
	int			padded;
	size_t		bytes_copied;

	padded = 0;
	initialize_sha224(&sha224);
	output_handle->at = 0;
	output_handle->args = args;
	bytes_copied = request_chunk(output_handle, sha224.digest, 64);
	while (bytes_copied >= 64 - 8)
	{
		ft_bzero(&sha224.chunk, sizeof(sha224.chunk));
		fill_chunk(sha224.digest->string, &sha224.chunk, 0, &padded);
		one_chunk(&sha224);
		make_digest_sha224(sha224.state, sha224.digest);
		bytes_copied = request_chunk(output_handle, sha224.digest, 64);
	}
	ft_bzero(&sha224.chunk, sizeof(sha224.chunk));
	fill_chunk(sha224.digest->string, &sha224.chunk, 1, &padded);
	sha224.chunk.block[15] = convert_endian_32bits(output_handle->at * 8);
	one_chunk(&sha224);
	make_digest_sha224(sha224.state, sha224.digest);
	sha224.digest->length = 56;
	return (sha224.digest);
}
