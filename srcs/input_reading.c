/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:06:07 by kmira             #+#    #+#             */
/*   Updated: 2019/10/14 02:46:47 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

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
	result = request_from_string(dest, bytes, output_handler);
	return (result);
}

size_t	request_from_string(t_string *dest, int bytes, t_output_handler *output_handler)
{
	char *src;
	size_t	amount_copied;

	src = &output_handler->args[output_handler->at];
	ft_bzero(dest->string, 64 + 1);
	amount_copied = ft_strncpy_i(dest->string, src, bytes);
	output_handler->at += amount_copied;
	return (amount_copied);
}
