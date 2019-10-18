/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:54:25 by kmira             #+#    #+#             */
/*   Updated: 2019/10/18 05:19:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

void	print_chunk(uint32_t block[16])
{
	int i;

	i = 0;
	while (i < 16)
	{
		printf("BLOCK[%2d]: %10u\n", i, block[i]);
		i++;
	}
	printf("\n");
}

void	print_w(uint32_t w[64])
{
	int i;

	i = 0;
	while (i < 64)
	{
		printf("w[%2d]: %12u\n", i, w[i]);
		i++;
	}
	printf("\n");
}

void	print_we(uint64_t w[80])
{
	int i;

	i = 0;
	while (i < 80)
	{
		printf("w[%2d]: %20llu\n", i, w[i]);
		i++;
	}
	printf("\n");
}
