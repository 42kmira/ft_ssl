/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:34:49 by kmira             #+#    #+#             */
/*   Updated: 2019/10/03 00:17:19 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "debug.h"

# include <stdlib.h>
# include <stddef.h>

# include "color.h"
# include "crypto_config.h"
# include "libft.h"

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: function_dispatch
*/

void	set_function(t_string *(*fun)(t_output_handler *, char **, int *),
					char *str);

#endif
