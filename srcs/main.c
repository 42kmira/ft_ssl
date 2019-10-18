/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:28:18 by kmira             #+#    #+#             */
/*   Updated: 2019/10/18 00:58:44 by kmira            ###   ########.fr       */
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
		print_usage_error();
	get_command(args[1], &crypto_function);
	ft_bzero(&output_handler, sizeof(output_handler));
	output_handler.command = args[1];
	if (is_without_input(args, 2, &output_handler.flags))
	{
		digest = crypto_function(&output_handler, STDIN_OPTION);
		print_output(&output_handler, digest, args[0]);
	}
	else
	{
		i = flag_loop(&output_handler, &args[FLAG_START], crypto_function) + 2;
		file_loop(&output_handler, &args[i], crypto_function);
	}
	// system("leaks ft_ssl");
	return (0);
}
