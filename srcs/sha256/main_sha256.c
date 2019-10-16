/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sha256.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:25:06 by kmira             #+#    #+#             */
/*   Updated: 2019/10/16 01:36:53 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"
#include "sha256.h"

#define RIGHT_BIT_ROTATE32(val, shift) ((val >> shift) | (val << (32 - shift)))
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

/*
** The conversion of endianness works in the following way:
** BASE:     1010 2010 | 3010 4010 | 5010 6010 | 7010 8010
** 8_SHIFT:  3010 4010 | 1010 2010 | 7010 8010 | 5010 6010
** 16_SHIFT: 7010 8010 | 5010 6010 | 3010 4010 | 1010 2010
*/

u_int32_t	convert_endian_32bits(u_int32_t val)
{
	u_int32_t x;

	x = ((0XFF00FF00 & val) >> 8)  | ((0X00FF00FF & val) << 8);
	x = ((0XFFFF0000 & x)   >> 16) | ((0X0000FFFF & x)   << 16);
	return (x);
}

static void	one_chunk(t_sha256 *sha256_info)
{
	int	i;
	uint32_t	w[64];
	uint32_t	s0;
	uint32_t	s1;

	i = 0;
	ft_bzero(&w, sizeof(w));
	while (i < 16)
	{
		sha256_info->chunk.block[i] = convert_endian_32bits(sha256_info->chunk.block[i]);
		w[i] = sha256_info->chunk.block[i];
		i++;
	}

	while (i < 64)
	{
		s0 = RIGHT_BIT_ROTATE32(w[i - 15], 7) ^ RIGHT_BIT_ROTATE32(w[i - 15], 18) ^ RIGHT_BIT_SHIFT32(w[i - 15], 3);
		s1 = RIGHT_BIT_ROTATE32(w[i - 2], 17) ^ RIGHT_BIT_ROTATE32(w[i - 2], 19) ^ RIGHT_BIT_SHIFT32(w[i - 2], 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}

	uint32_t a = sha256_info->state[h0];
	uint32_t b = sha256_info->state[h1];
	uint32_t c = sha256_info->state[h2];
	uint32_t d = sha256_info->state[h3];
	uint32_t e = sha256_info->state[h4];
	uint32_t f = sha256_info->state[h5];
	uint32_t g = sha256_info->state[h6];
	uint32_t h = sha256_info->state[h7];

	uint32_t S1;
	uint32_t S0;
	uint32_t ch;
	uint32_t maj;
	uint32_t temp1;
	uint32_t temp2;

	i = 0;
	while (i < 64)
	{
		S1 = (RIGHT_BIT_ROTATE32(e, 6) ^ (RIGHT_BIT_ROTATE32(e, 11)) ^ RIGHT_BIT_ROTATE32(e, 25));
		ch = (e & f) ^ ((~e) & g);
		temp1 = h + S1 + ch + g_k[i] + w[i];
		S0 = (RIGHT_BIT_ROTATE32(a, 2) ^ RIGHT_BIT_ROTATE32(a, 13) ^ RIGHT_BIT_ROTATE32(a, 22));
		maj = (a & b) ^ (a & c) ^ (b & c);
		temp2 = S0 + maj;
		h = g;
		g = f;
		f = e;
		e = d + temp1;
		d = c;
		c = b;
		b = a;
		a = temp1 + temp2;
		i++;
	}

	sha256_info->state[h0] = a + sha256_info->state[h0];
	sha256_info->state[h1] = b + sha256_info->state[h1];
	sha256_info->state[h2] = c + sha256_info->state[h2];
	sha256_info->state[h3] = d + sha256_info->state[h3];
	sha256_info->state[h4] = e + sha256_info->state[h4];
	sha256_info->state[h5] = f + sha256_info->state[h5];
	sha256_info->state[h6] = g + sha256_info->state[h6];
	sha256_info->state[h7] = h + sha256_info->state[h7];
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

struct s_string *crypto_algo_sha256(struct s_output_handler *output_handle, char *args)
{
	t_sha256	sha256;
	t_string	dest;
	int			padded;
	size_t		bytes_copied;

	padded = 0;
	sha256.state[h0] = 0x6a09e667;
	sha256.state[h1] = 0xbb67ae85;
	sha256.state[h2] = 0x3c6ef372;
	sha256.state[h3] = 0xa54ff53a;
	sha256.state[h4] = 0x510e527f;
	sha256.state[h5] = 0x9b05688c;
	sha256.state[h6] = 0x1f83d9ab;
	sha256.state[h7] = 0x5be0cd19;
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
	output_handle->flags |= Q_FLAG;
	return (sha256.digest);
}
