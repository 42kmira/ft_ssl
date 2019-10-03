/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:36:27 by kmira             #+#    #+#             */
/*   Updated: 2019/10/03 00:17:25 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#define ERROR_USAGE "usage: ft_ssl command [command opts] [command args]"

int		main(int aa, char **args)
{
	t_output_handler	*output_handler;
	t_string			*(*do_crypto_function)(t_output_handler *, char **, int *);
	int					i;

	if (aa <= 1)
		ft_puterror(""BOLDCYAN ERROR_USAGE COLOR_RESET);
	else
	{
		i = 1;
		set_function(do_crypto_function, args[i]);
		// while (i < aa)
		// {
		// 	// parse_flags(output_handler, args[i], &i);
		// 	// do_crypto_function(output_handler, args[i], &i);
		// 	// output_msg_digest(output_handler);
		// }
	}
	printf("Program Failed successfully\n");
	return (0);
}
