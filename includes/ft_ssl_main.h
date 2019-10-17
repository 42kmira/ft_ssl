/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_main.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:29:26 by kmira             #+#    #+#             */
/*   Updated: 2019/10/16 21:59:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MAIN_H
# define FT_SSL_MAIN_H

# include "debug.h"

# include "color.h"
# include "libft.h"
# include "ft_ssl_structs.h"

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include <errno.h>

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MACROS
*/

# define CMD_ONLY 2
# define FLAG_START 2

# define STDIN_OPTION NULL

# define COMPUTE_FUNCTION 1
# define TRY_NEXT_ARGUEMENT 1

# define TRY_FILE_LOOP 2

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** File: input_reading.c
*/

int			request_chunk(t_output *output_handler, t_string *dest);
size_t		request_from_string
			(t_string *dest, int bytes, t_output *output_handler);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** CRYPTO ALGORITHMS
** public handles for the cryto algoritms.
*/

t_string	*crypto_algo_md5(struct s_output *output_handle, char *args);
t_string	*crypto_algo_sha256(struct s_output *output_handle, char *args);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** File: output.c
** Formats the output of the message.
*/

void		print_output
	(t_output *output_handler, t_string *digest, char *args);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** File: function_dispatch.c
** Dispatch the crypto algorithm.
*/

void		get_command(char *key, t_string *(**result)(t_output *, char *));

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** File: utils.c
** Utility function providing misc functionality and readibility.
*/

void		ft_strnrev(char *str, size_t n);
size_t		ft_strncpy_i(char *dst, const char *src, size_t len);

int			flag_loop(t_output *output_handler, char **args,
			t_string *(*crypto_fun)(t_output *, char *));
void		file_loop(t_output *output_handler, char **args,
			t_string *(*crypto_fun)(t_output *, char *));

#endif
