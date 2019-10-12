/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:14:10 by kmira             #+#    #+#             */
/*   Updated: 2019/10/11 03:05:39 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

void	print_output(t_output_handler *output_handler, t_string *digest, char *args)
{
	if ((output_handler->flags & Q_FLAG) == 0 && (output_handler->flags & R_FLAG) == 0)
	{
		if (ft_strequ(output_handler->command, "md5"))
			write(1, "MD5 (\"", 7);
		if (ft_strequ(output_handler->command, "sha256"))
			write(1, "SHA256 (\"", 10);
		write(1, args, ft_strlen(args));
		write(1, "\") = ", 6);
	}
	write(1, digest->string, digest->length);
	if (output_handler->flags & R_FLAG)
	{
		write(1, " \"", 2);
		write(1, args, ft_strlen(args));
		write(1, "\"", 1);
	}
	write(1, "\n", 1);
}
