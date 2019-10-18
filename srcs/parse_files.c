/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:49:29 by kmira             #+#    #+#             */
/*   Updated: 2019/10/17 21:50:12 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

void	file_loop
	(t_output *output_handler, char **args,
	t_string *(*crypto_function)(t_output *, char *))
{
	int			i;
	t_string	*digest;

	i = 0;
	while (args[i] != NULL)
	{
		output_handler->flags |= F_FLAG;
		output_handler->fd = open(args[i], O_RDONLY);
		if (output_handler->fd == -1)
			printf("md5: Test0: No such file or directory\n");
		else
		{
			digest = crypto_function(output_handler, args[i]);
			print_output(output_handler, digest, args[i]);
		}
		output_handler->flags &= (~F_FLAG);
		i++;
	}
}
