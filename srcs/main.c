/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:28:18 by kmira             #+#    #+#             */
/*   Updated: 2019/10/17 21:07:42 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

int		main(int aa, char **args)
{
	t_output	output_handler;
	t_string	*(*crypto_function)(t_output *, char *);
	int			i;
	t_string	*digest;

	i = 0;
	if (aa <= 1)
		printf("USAGE ERROR\n");
	else
	{
		get_command(args[1], &crypto_function);
		ft_bzero(&output_handler, sizeof(output_handler));
		output_handler.command = args[1];
		if (aa == CMD_ONLY)
		{
			output_handler.flags |= P_FLAG | O_FLAG;
			digest = crypto_function(&output_handler, STDIN_OPTION);
			print_output(&output_handler, digest, args[0]);
		}
		else
		{
			i = flag_loop(&output_handler, &args[FLAG_START], crypto_function) + FLAG_START;
			file_loop(&output_handler, &args[i], crypto_function);
		}
	}
	system("leaks ft_ssl");
	return (0);
}
