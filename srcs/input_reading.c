/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:06:07 by kmira             #+#    #+#             */
/*   Updated: 2019/10/13 20:15:19 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

void	request_from_string(t_string *dest, int bytes, t_output_handler *output_handler)
{
	ft_bzero(dest->string, dest->length);
	// ft_strncpy();
	(void)dest;
	(void)bytes;
	(void)output_handler;
	return ;
}
