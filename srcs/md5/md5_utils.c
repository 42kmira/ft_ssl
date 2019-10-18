/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:15:29 by kmira             #+#    #+#             */
/*   Updated: 2019/10/17 18:22:32 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"
#include "main_md5.h"

void	initialize_md5(t_md5 *md5_info)
{
	md5_info->state[A] = 0x67452301;
	md5_info->state[B] = 0xefcdab89;
	md5_info->state[C] = 0x98badcfe;
	md5_info->state[D] = 0x10325476;
	md5_info->digest = malloc(sizeof(*md5_info->digest) * (1));
	md5_info->digest->string = malloc(sizeof(*md5_info->digest) * (32));
	md5_info->digest->length = 32;
}
