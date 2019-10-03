/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_dispatch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:16:06 by kmira             #+#    #+#             */
/*   Updated: 2019/10/03 00:18:17 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_function(t_string *(*fun)(t_output_handler *, char **, int *),
					char *str)
{
	int i;

	i = 0;
	while (g_crypto_dispatch_table[i].function != NULL_CRYPTO_FUNCTION)
	{
		if (ft_strcmp(str, g_crypto_dispatch_table[i].name) == 0)
		{
			fun = g_crypto_dispatch_table[i].function;
			break ;
		}
		i++;
	}
	if (g_crypto_dispatch_table[i].function == NULL_CRYPTO_FUNCTION)
	{
		ft_putstr(BOLDRED"ft_ssl error: "COLOR_RESET);
		ft_putstr(str);
		ft_puterror(BOLDRED" crypto function does not exist!"COLOR_RESET);
	}
}
