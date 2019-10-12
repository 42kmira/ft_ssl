/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:28:18 by kmira             #+#    #+#             */
/*   Updated: 2019/10/12 00:10:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

int		main(int aa, char **args)
{
	t_output_handler	output_handler;
	t_string			*(*crypto_function)(t_output_handler *, char *);

	if (aa <= 1)
		printf("USAGE ERROR\n");
	else
	{
		get_command(args[1], &crypto_function);
		ft_bzero(&output_handler, sizeof(output_handler));
		output_handler.command = args[1];
		if (aa == CMD_ONLY)
		{
			output_handler.flags |= P_FLAG;
			printf("Running function on stdin\n");
			crypto_function(&output_handler, STDIN_OPTION);
		}
		else
		{
			// printf("Do Flags\n");
			flag_loop(&output_handler, &args[FLAG_START], crypto_function);
			// printf("Then files if there are any\n");
		}
	}
	return (0);
}
