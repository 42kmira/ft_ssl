/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypto_config.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:26:07 by kmira             #+#    #+#             */
/*   Updated: 2019/10/03 00:16:31 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRYPTO_CONFIG_H
# define CRYPTO_CONFIG_H

# include "crypto_main_structs.h"

static t_flag_pair	g_flag_array[] =
{
	{'P', P_FLAG},
	{'Q', Q_FLAG},
	{'R', R_FLAG},
	{'S', S_FLAG},
	{'\0', NO_FLAG}
};

extern	t_flag_pair g_flag_array[];

t_string *crypto_algo_md5(t_output_handler *output_handle, char **args, int *index);
t_string *crypto_algo_sha256(t_output_handler *output_handle, char **args, int *index);

#define NULL_CRYPTO_FUNCTION NULL

static t_function_pair g_crypto_dispatch_table[] =
{
	{"md5", crypto_algo_md5},
	{"sha256", crypto_algo_sha256},
	{"\0", NULL_CRYPTO_FUNCTION}
};

static t_function_pair g_crypto_dispatch_table[];

#endif
