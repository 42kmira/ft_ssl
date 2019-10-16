/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_md5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:51:28 by kmira             #+#    #+#             */
/*   Updated: 2019/10/16 01:34:48 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"
#include "md5.h"

#define MD5_F(X, Y, Z) ((X & Y) | ((~X) & Z))
#define MD5_G(X, Y, Z) ((X & Z) | (Y & (~Z)))
#define MD5_H(X, Y, Z) (X ^ Y ^ Z)
#define MD5_I(X, Y, Z) (Y ^ (X | (~Z)))

#define LEFT_BIT_ROTATE32(val, shift) ((val << shift) | (val >> (32 - shift)))

static void	make_digest_md5(uint32_t block[4], t_string *dest)
{
	int			i;
	u_int32_t	num;

	i = 0;
	while (i < 4)
	{
		num = block[i];
		dest->string[(i * 8) + 1] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 0] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 3] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 2] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 5] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 4] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 7] = g_digits[num % 16];
		num = num / 16;
		dest->string[(i * 8) + 6] = g_digits[num % 16];
		i++;
	}
}

static void	one_chunk(t_md5 *md5_info)
{
	int i;
	u_int32_t	g;
	u_int32_t	f;

	u_int32_t a = md5_info->state[A];
	u_int32_t b = md5_info->state[B];
	u_int32_t c = md5_info->state[C];
	u_int32_t d = md5_info->state[D];

	i = 0;
	while (i < 64)
	{
		if (i <= 15)
		{
			f = MD5_F(b, c, d);
			g = i;
		}
		else if (i <= 31)
		{
			f = MD5_G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		else if (i <= 47)
		{
			f = MD5_H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		else
		{
			f = MD5_I(b, c, d);
			g = (7 * i) % 16;
		}
		f = f + a + g_k[i] + md5_info->chunk.block[g];
		a = d;
		d = c;
		c = b;
		b = b + LEFT_BIT_ROTATE32(f, g_s[i]);
		i++;
	}
	md5_info->state[A] = a + md5_info->state[A];
	md5_info->state[B] = b + md5_info->state[B];
	md5_info->state[C] = c + md5_info->state[C];
	md5_info->state[D] = d + md5_info->state[D];
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
		chunk->block[14] = at * 8;
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

struct s_string	*crypto_algo_md5   (struct s_output_handler *output_handle, char *args)
{
	t_md5		md5;
	t_string	dest;
	int			padded;
	size_t		bytes_copied;

	padded = 0;
	md5.state[A] = 0x67452301;
	md5.state[B] = 0xefcdab89;
	md5.state[C] = 0x98badcfe;
	md5.state[D] = 0x10325476;

	md5.digest = malloc(sizeof(*md5.digest) * (1));
	md5.digest->string = malloc(sizeof(*md5.digest) * (32));
	md5.digest->length = 32;

	dest.string = malloc(sizeof(*dest.string) * (64 + 1));
	dest.length = 64;

	output_handle->at = 0;
	output_handle->args = args;

	bytes_copied = request_chunk(output_handle, &dest);
	while (bytes_copied >= 64 - 8)
	{
		ft_bzero(&md5.chunk, sizeof(md5.chunk));
		fill_chunk(dest.string, &md5.chunk, 0, output_handle->at, &padded);
		one_chunk(&md5);
		make_digest_md5(md5.state, md5.digest);
		bytes_copied = request_chunk(output_handle, &dest);
	}
	fill_chunk(dest.string, &md5.chunk, 1, output_handle->at, &padded);
	one_chunk(&md5);
	make_digest_md5(md5.state, md5.digest);
	output_handle->flags |= Q_FLAG;
	return (md5.digest);
}

