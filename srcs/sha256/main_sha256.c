/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sha256.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:25:06 by kmira             #+#    #+#             */
/*   Updated: 2019/10/17 10:58:37 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"
#include "main_sha256.h"

#define R_BIT_ROT32(val, shift) ((val >> shift) | (val << (32 - shift)))
#define RIGHT_BIT_SHIFT32(val, shift) ((val >> shift))

static void	make_digest_sha256(uint32_t block[16], t_string *dest)
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

static void	compression_function(uint32_t *state[8], uint32_t *w[8])
{
	int			i;
	uint32_t	num[6];

	i = 0;
	while (i++ <= 64)
	{
		num[S1] = (R_BIT_ROT32(*state[H4], 6) ^ (R_BIT_ROT32(*state[H4], 11))
				^ R_BIT_ROT32(*state[H4], 25));
		num[CH] = (*state[H4] & *state[H5])
				^ ((~*state[H4]) & *state[H6]);
		num[TEMP1] = *state[H7] + num[S1] + num[CH] + g_k[i] + *w[i];
		num[S0] = (R_BIT_ROT32(*state[H0], 2) ^ R_BIT_ROT32(*state[H0], 13)
				^ R_BIT_ROT32(*state[H0], 22));
		num[MAJ] = (*state[H0] & *state[H1]) ^ (*state[H0] & *state[H2])
				^ (*state[H1] & *state[H2]);
		num[TEMP2] = num[S0] + num[MAJ];
		*state[H7] = *state[H6];
		*state[H6] = *state[H5];
		*state[H5] = *state[H4];
		*state[H4] = *state[H3] + num[TEMP1];
		*state[H3] = *state[H2];
		*state[H2] = *state[H1];
		*state[H1] = *state[H0];
		*state[H0] = num[TEMP1] + num[TEMP2];
	}
}

static void	one_chunk(t_sha256 *sha256_info)
{
	int			i;
	uint32_t	w[64];
	uint32_t	state[8];
	uint32_t	s0;
	uint32_t	s1;

	i = -1;
	ft_bzero(&w, sizeof(w));
	while (i++ < 16)
	{
		sha256_info->chunk.block[i] = convert_endian_32bits(sha256_info->chunk.block[i]);
		w[i] = sha256_info->chunk.block[i];
	}
	while (i < 64)
	{
		s0 = R_BIT_ROT32(w[i - 15], 7) ^ R_BIT_ROT32(w[i - 15], 18)
			^ RIGHT_BIT_SHIFT32(w[i - 15], 3);
		s1 = R_BIT_ROT32(w[i - 2], 17) ^ R_BIT_ROT32(w[i - 2], 19)
			^ RIGHT_BIT_SHIFT32(w[i - 2], 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
	i = -1;
	while (i++ < 8)
		state[i] = sha256_info->state[i];
	compression_function(&state, *w);
	i = -1;
	while (i++ < 8)
		sha256_info->state[i] = state[i] + sha256_info->state[i];
}

static void	fill_chunk(char *str, t_512_chunk *chunk, int final, int at, int *padded)
{
	int			i;
	int			j;
	int			len;
	int			stop;
	t_conveter	transmutation_decive;

	len = ft_strlen(str);
	ft_bzero(chunk, 512);
	i = 0;
	stop = 16;
	if (final == 1)
		stop = 13;
	while (i < stop)
	{
		if ((i + 1) * 4 >= len)
			break ;
		transmutation_decive.num = 0;
		ft_strncpy(transmutation_decive.args, &str[i * 4], 4);
		chunk->block[i] = transmutation_decive.num;
		i++;
	}
	transmutation_decive.num = 0;
	j = 0;
	while (str[i * 4 + j] != '\0' && j < 4)
	{
		transmutation_decive.args[j] = str[i * 4 + j];
		j++;
	}
	if (final == 1)
		chunk->block[15] = convert_endian_32bits(at * 8);
	if (len < 64 && *padded == 0)
	{
		if (j == 4)
		{
			chunk->block[i] = transmutation_decive.num;
			transmutation_decive.num = 0;
			transmutation_decive.args[0] = 0b10000000;
			i++;
		}
		else
			transmutation_decive.args[j] = 0b10000000;
		*padded = 1;
	}
	chunk->block[i] = transmutation_decive.num;
}

t_string	*crypto_algo_sha256(t_output *output_handle, char *args)
{
	t_sha256	sha256;
	t_string	dest;
	int			padded;
	size_t		bytes_copied;

	padded = 0;
	sha256.state[H0] = 0x6a09e667;
	sha256.state[H1] = 0xbb67ae85;
	sha256.state[H2] = 0x3c6ef372;
	sha256.state[H3] = 0xa54ff53a;
	sha256.state[H4] = 0x510e527f;
	sha256.state[H5] = 0x9b05688c;
	sha256.state[H6] = 0x1f83d9ab;
	sha256.state[H7] = 0x5be0cd19;
	sha256.digest = malloc(sizeof(*sha256.digest) * (1));
	sha256.digest->string = malloc(sizeof(*sha256.digest) * (64));
	sha256.digest->length = 64;
	dest.string = malloc(sizeof(*dest.string) * (64 + 1));
	dest.length = 64;
	output_handle->at = 0;
	output_handle->args = args;
	bytes_copied = request_chunk(output_handle, &dest);
	while (bytes_copied >= 64 - 8)
	{
		ft_bzero(&sha256.chunk, sizeof(sha256.chunk));
		fill_chunk(dest.string, &sha256.chunk, 0, output_handle->at, &padded);
		one_chunk(&sha256);
		make_digest_sha256(sha256.state, sha256.digest);
		bytes_copied = request_chunk(output_handle, &dest);
	}
	fill_chunk(dest.string, &sha256.chunk, 1, output_handle->at, &padded);
	one_chunk(&sha256);
	make_digest_sha256(sha256.state, sha256.digest);
	return (sha256.digest);
}
