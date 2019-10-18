/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:17:53 by kmira             #+#    #+#             */
/*   Updated: 2019/10/18 04:18:28 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"
#include "main_sha224.h"

void	initialize_sha224(t_sha224 *sha224_info)
{
	sha224_info->state[H0] = 0xc1059ed8;
	sha224_info->state[H1] = 0x367cd507;
	sha224_info->state[H2] = 0x3070dd17;
	sha224_info->state[H3] = 0xf70e5939;
	sha224_info->state[H4] = 0xffc00b31;
	sha224_info->state[H5] = 0x68581511;
	sha224_info->state[H6] = 0x64f98fa7;
	sha224_info->state[H7] = 0xbefa4fa4;
	sha224_info->digest = malloc(sizeof(*sha224_info->digest) * (1));
	sha224_info->digest->string = malloc(sizeof(*sha224_info->digest) * (64));
	sha224_info->digest->length = 64;
}
