/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:34:49 by kmira             #+#    #+#             */
/*   Updated: 2019/10/03 00:21:31 by kmira            ###   ########.fr       */
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
** FILE: function_dispatch.c
** Sets which function the program will run.
*/

void	set_function(t_string *(*fun)(t_output_handler *, char **, int *),
					char *str);


/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: parse_flags.c
** Parses the flags.
*/

void	parse_flags(t_output_handler *output_handler, char **args);
void	override_flags(t_output_handler *output_handler);

#endif
