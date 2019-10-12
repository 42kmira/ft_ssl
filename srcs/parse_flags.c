/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:03:03 by kmira             #+#    #+#             */
/*   Updated: 2019/10/11 02:13:26 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

void		turn_flag_on(char key, enum e_flags *result)
{
	int		i;
	char	lock;

	i = 0;
	while (g_flag_array[i].flag_value != NO_FLAG)
	{
		lock = g_flag_array[i].pair;
		if (key == lock)
			break ;
		i++;
	}
	if (g_flag_array[i].flag_value == NO_FLAG)
		ft_puterror("Sorry this is not a legal option =[");
	else
		*result |= g_flag_array[i].flag_value;
}

int		fetch_flags(enum e_flags *result, char **args, int *i, int *j)
{
	char	key;

	while (args[*i])
	{
		while (args[*i][*j] != '\0')
		{
			key = args[*i][*j];
			turn_flag_on(key, result);
			if (*result & (ARGUMENT_FLAGS))
				return (COMPUTE_FUNCTION);
			*j = *j + 1;
		}
		if (args[*i + 1] && args[*i + 1][0] == '-')
		{
			*j = 1;
			*i = *i + 1;
		}
		else
			return (TRY_FILE_LOOP);
	}
	return (0);
}

/*
** This cleans up the flags and gets things ready for the next flag read.
** The logic here is particular to the flags that affect something with arguements
** namely the -p and -s flags.
** This helps keep things seperate.
*/

int		setup_next_flag_read(t_output_handler *output_handler, int *i, int *j, char **args)
{
	if (output_handler->flags & S_FLAG)
	{
		output_handler->flags = output_handler->flags & ~(S_FLAG);
		*i = *i + 1;
		*j = 0;
	}
	if (output_handler->flags & P_FLAG)
	{
		output_handler->flags = output_handler->flags & ~(P_FLAG);
		*j = *j + 1;
	}
	else
	{
		if (args[*i] && args[*i][0] == '-')
			*j = *j + 1;
		else
			return (TRY_FILE_LOOP);
	}
	return (TRY_NEXT_ARGUEMENT);
}

/*
** Sets i and j values to the correct spot.
** This gets args in the right position for the crypto function
*/

void		ready_input(char **args, int *i, int *j, t_output_handler *output_handler)
{
	if (output_handler->flags & S_FLAG)
	{
		if (args[*i][*j + 1] == '\0')
		{
			*j = 0;
			*i = *i + 1;
		}
		else
			*j = *j + 1;
		if (args[*i] == NULL)
			ft_puterror("We require some sort of arguement\n");
	}
}

/*
** This will need to probably return where it left off or something to continie
** the file parsing.
*/

void	override_flags(t_output_handler *output_handler)
{
	if (output_handler->flags & (Q_FLAG))
		output_handler->flags &= ~(R_FLAG);
}

void		flag_loop(t_output_handler *output_handler, char **args, t_string *(*crypto_function)(t_output_handler *, char *))
{
	int			i;
	int			j;
	int			flag_result;
	t_string	*digest;

	i = 0;
	j = 0;
	if (args[i][j] != '-')
		return ;
	else
		j = j + 1;
	while (args[i] != NULL)
	{
		flag_result = fetch_flags(&output_handler->flags, args, &i, &j);
		override_flags(output_handler);
		ready_input(args, &i, &j, output_handler);
		if (flag_result == COMPUTE_FUNCTION)
		{
			digest = crypto_function(output_handler, &args[i][j]);
			print_output(output_handler, digest, &args[i][j]);
		}
		else if (flag_result == TRY_FILE_LOOP)
			break ; //Maybe return, don't know right now
		flag_result = setup_next_flag_read(output_handler, &i, &j, args);
		if (flag_result == TRY_FILE_LOOP)
			break ;
	}
}

void		file_loop(t_output_handler *output_handler, char **args)
{
	(void)output_handler;
	(void)args;
}

