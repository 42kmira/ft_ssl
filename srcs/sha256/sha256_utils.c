/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:17:53 by kmira             #+#    #+#             */
/*   Updated: 2019/10/17 18:22:16 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"
#include "main_sha256.h"

void	initialize_sha256(t_sha256 *sha256_info)
{
	sha256_info->state[H0] = 0x6a09e667;
	sha256_info->state[H1] = 0xbb67ae85;
	sha256_info->state[H2] = 0x3c6ef372;
	sha256_info->state[H3] = 0xa54ff53a;
	sha256_info->state[H4] = 0x510e527f;
	sha256_info->state[H5] = 0x9b05688c;
	sha256_info->state[H6] = 0x1f83d9ab;
	sha256_info->state[H7] = 0x5be0cd19;
	sha256_info->digest = malloc(sizeof(*sha256_info->digest) * (1));
	sha256_info->digest->string = malloc(sizeof(*sha256_info->digest) * (64));
	sha256_info->digest->length = 64;
}
