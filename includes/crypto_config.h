/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypto_config.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 00:26:07 by kmira             #+#    #+#             */
/*   Updated: 2019/10/02 00:32:51 by kmira            ###   ########.fr       */
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

#endif
