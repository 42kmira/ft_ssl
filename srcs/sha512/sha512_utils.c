/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:17:53 by kmira             #+#    #+#             */
/*   Updated: 2019/10/18 15:01:17 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"
#include "main_sha512.h"

void	initialize_sha512(t_sha512 *sha512_info)
{

	sha512_info->state[H0] = 0x6a09e667f3bcc908;
	sha512_info->state[H1] = 0xbb67ae8584caa73b;
	sha512_info->state[H2] = 0x3c6ef372fe94f82b;
	sha512_info->state[H3] = 0xa54ff53a5f1d36f1;
	sha512_info->state[H4] = 0x510e527fade682d1;
	sha512_info->state[H5] = 0x9b05688c2b3e6c1f;
	sha512_info->state[H6] = 0x1f83d9abfb41bd6b;
	sha512_info->state[H7] = 0x5be0cd19137e2179;
	sha512_info->digest = malloc(sizeof(*sha512_info->digest) * (1));
	sha512_info->digest->string = malloc(sizeof(*sha512_info->digest) * (128));
	sha512_info->digest->length = 128;
}

void	make_digest_sha512(uint64_t block[16], t_string *dest)
{
	int			i;
	int			j;
	u_int64_t	num;

	i = 0;
	while (i < 16)
	{
		num = block[7 - i];
		j = 0;
		while (j < 16)
		{
			dest->string[(i * 16) + j] = g_digits[num % 16];
			num = num / 16;
			j++;
		}
		i++;
	}
	ft_strnrev(dest->string, dest->length);
}