/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_input_reading.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:06:07 by kmira             #+#    #+#             */
/*   Updated: 2019/10/18 00:39:28 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

size_t	request_from_string(t_string *dest, int bytes, t_output *output_handler)
{
	char	*src;
	size_t	amount_copied;

	src = &output_handler->args[output_handler->at];
	ft_bzero(dest->string, 64 + 1);
	amount_copied = ft_strncpy_i(dest->string, src, bytes);
	output_handler->at += amount_copied;
	return (amount_copied);
}

size_t	request_from_file(t_string *dest, int bytes, t_output *output_handler)
{
	int	fd;
	int	result;

	fd = output_handler->fd;
	ft_bzero(dest->string, 64 + 1);
	result = read(fd, dest->string, bytes);
	bytes -= result;
	while (bytes && output_handler->flags & P_FLAG)
	{
		if (result == 0)
			break ;
		result = read(fd, &dest->string[64 - bytes], bytes);
		bytes -= result;
	}
	if (output_handler->flags & P_FLAG && (output_handler->flags & O_FLAG) == 0)
		write(1, dest->string, 64 - bytes);
	output_handler->at += result;
	if (output_handler->flags & P_FLAG)
	{
		output_handler->at += (64 - bytes - result);
		return (64 - bytes);
	}
	return (result);
}

int		request_chunk(t_output *output_handler, t_string *dest)
{
	int		result;
	int		bytes;
	int		fd;

	result = 0;
	bytes = 64;
	fd = output_handler->fd;
	if (output_handler->flags & F_FLAG)
		result = request_from_file(dest, bytes, output_handler);
	else if (output_handler->flags & P_FLAG)
	{
		output_handler->fd = 0;
		result = request_from_file(dest, bytes, output_handler);
	}
	else if (output_handler->flags & S_FLAG)
		result = request_from_string(dest, bytes, output_handler);
	else
		ft_puterror("This we cannot read from");
	return (result);
}
