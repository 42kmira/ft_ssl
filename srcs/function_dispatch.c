/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_dispatch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:43:40 by kmira             #+#    #+#             */
/*   Updated: 2019/10/18 00:58:10 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

void	get_command(char *key, t_string *(**result)(t_output *, char *))
{
	int		i;
	char	*command_name;

	i = 0;
	*result = NULL;
	while (g_crypto_dispatch_table[i].function != NULL)
	{
		command_name = g_crypto_dispatch_table[i].name;
		if (ft_strequ(key, command_name))
			*result = g_crypto_dispatch_table[i].function;
		i++;
	}
	if (*result == NULL)
		print_wrong_command(key);
}
