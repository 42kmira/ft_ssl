/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_md5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:51:28 by kmira             #+#    #+#             */
/*   Updated: 2019/10/13 20:06:30 by kmira            ###   ########.fr       */
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

typedef union	u_converter
{
	u_int32_t	num;
	char		args[4];
}				t_conveter;

void	fill_chunk(char *str, t_512_chunk *chunk, int final)
{
	int	i;
	int	j;
	int	len;
	int	stop;
	t_conveter	transmutation_decive;

	len = ft_strlen(str);
	i = 0;
	stop = 16;
	if (final == 1)
		stop = 12;
	while (i < stop)
	{
		if ((i + 1) * 4 > len)
			break ;
		transmutation_decive.num = 0;
		ft_strncpy(transmutation_decive.args, &str[i * 4], 4);
		chunk->block[i] = transmutation_decive.num;
		i++;
	}
	transmutation_decive.num = 0;
	j = 0;
	while (str[i * 4 + j] != '\0')
	{
		transmutation_decive.args[j] = str[i * 4 + j];
		j++;
	}
	transmutation_decive.args[j] = 0b10000000;
	chunk->block[i] = transmutation_decive.num;
	chunk->block[14] = len * 8;
}

int		request_chunk(t_output_handler *output_handler, t_string *dest)
{
	int		result;
	int		bytes;
	int		fd;

	result = 0;
	bytes = 64;
	fd = output_handler->fd;
	// if (output_handler->flags & F_FLAG)
	// 	result = request_from_file(fd, dest, bytes);
	// else if (output_handler->flags & P_FLAG)
	// 	result = request_from_file(0, dest, bytes);
	// else if (output_handler->flags & S_FLAG)
	// 	result = request_from_string(dest, bytes);
	// else
	// 	ft_puterror("This we cannot read from");
	request_from_string(dest, bytes, output_handler);
	return (result);
}

struct s_string	*crypto_algo_md5   (struct s_output_handler *output_handle, char *args)
{
	t_md5		md5;
	t_string	dest;

	md5.state[A] = 0x67452301;
	md5.state[B] = 0xefcdab89;
	md5.state[C] = 0x98badcfe;
	md5.state[D] = 0x10325476;

	// printf("Doing md5 on input %s\n", args);
	md5.digest = malloc(sizeof(*md5.digest) * (1));
	md5.digest->string = malloc(sizeof(*md5.digest) * (32));
	md5.digest->length = 32;

	dest.string = malloc(sizeof(*dest.string) * (512));
	dest.length = 0;

	output_handle->at = 0;
	output_handle->args = args;

	// while (request_chunk(output_handle, dest) != 0)
	// {
	// 	ft_bzero(&md5.chunk, sizeof(md5.chunk));
	// 	fill_chunk(args, &md5.chunk, 0);
	// 	print_chunk(&md5.chunk);
	// 	one_chunk(&md5);
	// }
	fill_chunk(args, &md5.chunk, 1);
	one_chunk(&md5);
	make_digest_md5(md5.state, md5.digest);

	(void)output_handle;
	(void)args;
	return (md5.digest);
}

