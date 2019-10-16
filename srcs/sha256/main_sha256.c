/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sha256.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:25:06 by kmira             #+#    #+#             */
/*   Updated: 2019/10/15 18:36:56 by kmira            ###   ########.fr       */
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

u_int32_t	convert_endian_32bits(u_int32_t val)
{
	u_int32_t x;

	x = ((0XFF00FF00 & val) >> 8)  | ((0X00FF00FF & val) << 8);
	x = ((0XFFFF0000 & x)   >> 16) | ((0X0000FFFF & x)   << 16);
	return (x);
}

// 1010 2010 | 3010 4010 | 5010 6010 | 7010 8010
// 3010 4010 | 1010 2010 | 7010 8010 | 5010 6010
// 7010 8010 | 5010 6010 | 3010 4010 | 1010 2010

static void	one_chunk(t_sha256 *sha256_info)
{
	int	i;
	u_int32_t	w[64];
	u_int32_t	s0;
	u_int32_t	s1;

	i = 0;
	while (i < 16)
	{
		sha256_info->chunk.block[i] = convert_endian_32bits(sha256_info->chunk.block[i]);
		i++;
	}

	i = 0;
	while (i < 16)
	{
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

	i = 0;
	while (i < 64)
	{
		// printf("w[%2d]: %12u\n", i, w[i]);
		printf("w[%2d]: %12u\n", i, w[i]);
		i++;
	}

	u_int32_t a = g_h[0];
	u_int32_t b = g_h[1];
	u_int32_t c = g_h[2];
	u_int32_t d = g_h[3];
	u_int32_t e = g_h[4];
	u_int32_t f = g_h[5];
	u_int32_t g = g_h[6];
	u_int32_t h = g_h[7];

	u_int32_t S1;
	u_int32_t S0;
	u_int32_t ch;
	u_int32_t maj;
	u_int32_t temp1;
	u_int32_t temp2;

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

	sha256_info->chunk.block[0] = a + g_h[0];
	sha256_info->chunk.block[1] = b + g_h[1];
	sha256_info->chunk.block[2] = c + g_h[2];
	sha256_info->chunk.block[3] = d + g_h[3];
	sha256_info->chunk.block[4] = e + g_h[4];
	sha256_info->chunk.block[5] = f + g_h[5];
	sha256_info->chunk.block[6] = g + g_h[6];
	sha256_info->chunk.block[7] = h + g_h[7];
}

struct s_string *crypto_algo_sha256(struct s_output_handler *output_handle, char *args)
{
	t_sha256	sha256;
	t_512_chunk	chunk;
	u_int32_t	n;
	size_t		bytes_copied;
	int			padded;

	padded = 0;
	n = (u_int32_t)&args[0];

	chunk.block[0]  = 1953719636;
	chunk.block[1]  = 128;
	chunk.block[2]  = 0;
	chunk.block[3]  = 0;
	chunk.block[4]  = 0;
	chunk.block[5]  = 0;
	chunk.block[6]  = 0;
	chunk.block[7]  = 0;
	chunk.block[8]  = 0;
	chunk.block[9]  = 0;
	chunk.block[10] = 0;
	chunk.block[11] = 0;
	chunk.block[12] = 0;
	chunk.block[13] = 0;
	chunk.block[14] = 0;
	chunk.block[15] = 536870912;

	printf("Doing sha256 on input %s\n", args);
	sha256.digest = malloc(sizeof(*sha256.digest) * (1));
	sha256.digest->string = malloc(sizeof(*sha256.digest) * (64));
	sha256.digest->length = 64;
	sha256.chunk = chunk;

	bytes_copied = 0;

	// while (bytes_copied >= 64 - 8)
	// {
	// 	ft_bzero(&sha256, sizeof(sha256.chunk));
	// 	//fill_chunk
	// 	one_chunk(&sha256);
	// 	make_digest_sha256(&sha256.digest, );
	// }

	one_chunk(&sha256);
	make_digest_sha256(sha256.chunk.block, sha256.digest);

	(void)output_handle;
	(void)args;
	return (sha256.digest);
}
