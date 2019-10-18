/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:49:29 by kmira             #+#    #+#             */
/*   Updated: 2019/10/18 01:43:52 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

int		is_without_input(char **args, int start, enum e_flags *result)
{
	int	j;

	while (args[start] != NULL)
	{
		if (args[start][0] == '-')
		{
			j = 1;
			while (args[start][j])
			{
				turn_flag_on(args[start][j], result);
				if (*result & (ARGUMENT_FLAGS))
				{
					*result &= ~(ARGUMENT_FLAGS);
					return (0);
				}
				j++;
			}
		}
		else
			return (0);
		start++;
	}
	*result |= P_FLAG | O_FLAG;
	return (1);
}

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
		if (output_handler->fd == -1 || (read(output_handler->fd, &i, 0)))
			print_file_err(args[i], output_handler->command);
		else
		{
			digest = crypto_function(output_handler, args[i]);
			print_output(output_handler, digest, args[i]);
		}
		output_handler->flags &= (~F_FLAG);
		i++;
	}
}
