/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:41:20 by kmira             #+#    #+#             */
/*   Updated: 2019/10/02 23:51:44 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	parse_flags(t_output_handler *output_handler, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i] != '\0')
	{
		j = 0;
		while (g_flag_array[j].flag_value != NO_FLAG)
		{
			if (g_flag_array[j].pair == args[i][j])
			{
				output_handler->flags |= g_flag_array[j].flag_value;
				break ;
			}
			j++;
		}
		if (output_handler->flags & S_FLAG)
			break ;
		i++;
	}
}

void	override_flags(t_output_handler *output_handler)
{
	if (output_handler->flags & (R_FLAG | Q_FLAG))
		output_handler->flags &= ~(R_FLAG);
}
