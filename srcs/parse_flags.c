/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:41:20 by kmira             #+#    #+#             */
/*   Updated: 2019/10/03 00:44:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	override_flags(t_output_handler *output_handler)
{
	if (output_handler->flags & (R_FLAG | Q_FLAG))
		output_handler->flags &= ~(R_FLAG);
}

void	parse_flags(t_output_handler *output_handler, char **args, int *index)
{
	int	j;
	int	k;

	j = 0;
	while (args[*index][j] == '-')
	{
		j = 0;
		while (args[*index][j] != '\0')
		{
			while (g_flag_array[k].flag_value != NO_FLAG)
			{
				if (g_flag_array[k].pair == args[*index][j])
				{
					output_handler->flags |= g_flag_array[k].flag_value;
					break ;
				}
				k++;
			}
			if (output_handler->flags & S_FLAG)
				break ;
			j++;
		}
		if (output_handler->flags & S_FLAG)
			break ;
		*index = *index + 1;
	}
	override_flags(output_handler);
}

