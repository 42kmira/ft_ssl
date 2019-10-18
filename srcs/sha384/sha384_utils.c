/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:17:53 by kmira             #+#    #+#             */
/*   Updated: 2019/10/18 15:05:41 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"
#include "main_sha384.h"


void	initialize_sha384(t_sha384 *sha384_info)
{
	sha384_info->state[H0] = 0xcbbb9d5dc1059ed8;
	sha384_info->state[H1] = 0x629a292a367cd507;
	sha384_info->state[H2] = 0x9159015a3070dd17;
	sha384_info->state[H3] = 0x152fecd8f70e5939;
	sha384_info->state[H4] = 0x67332667ffc00b31;
	sha384_info->state[H5] = 0x8eb44a8768581511;
	sha384_info->state[H6] = 0xdb0c2e0d64f98fa7;
	sha384_info->state[H7] = 0x47b5481dbefa4fa4;
	sha384_info->digest = malloc(sizeof(*sha384_info->digest) * (1));
	sha384_info->digest->string = malloc(sizeof(*sha384_info->digest) * (128));
	sha384_info->digest->length = 128;
}

void	make_digest_sha384(uint64_t block[16], t_string *dest)
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