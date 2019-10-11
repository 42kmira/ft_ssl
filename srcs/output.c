/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:14:10 by kmira             #+#    #+#             */
/*   Updated: 2019/10/10 22:23:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

void	print_output(t_output_handler *output_handler, t_string *digest, char *args)
{
	// if (output_handler->flags & Q)
	write(1, "MD5 (\"", 7);
	write(1, args, ft_strlen(args));
	write(1, "\") = ", 6);
	write(1, digest->string, digest->length);
	write(1, "\n", 1);
}
