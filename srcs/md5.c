/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 23:57:05 by kmira             #+#    #+#             */
/*   Updated: 2019/10/02 23:59:42 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_string *crypto_algo_md5(t_output_handler *output_handle, char **args, int *index)
{
	t_string *output;

	output = malloc(sizeof(*output));
	printf("This jsut did md5");
	return (output);
}

t_string *crypto_algo_sha256(t_output_handler *output_handle, char **args, int *index)
{
	t_string *output;

	output = malloc(sizeof(*output));
	printf("This jsut did sha256");
	return (output);
}
