/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_config.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:38:07 by kmira             #+#    #+#             */
/*   Updated: 2019/10/16 21:27:03 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_CONFIG_H
# define FT_SSL_CONFIG_H

# include <stddef.h>

static char g_digits[] = "0123456789abcdef";

enum e_flags
{
    PREVIOUSLY_P = 0b00000001,
	O_FLAG       = 0b00000010,
    F_FLAG       = 0b00000100,
    P_FLAG       = 0b00001000,
    Q_FLAG       = 0b00010000,
    R_FLAG       = 0b00100000,
    S_FLAG       = 0b01000000,
    NO_FLAG      = 0b10000000
};

# define ARGUMENT_FLAGS (S_FLAG | P_FLAG)

typedef struct	s_flag_pair
{
	int				pair;
	enum e_flags	flag_value;
}				t_flag_pair;

static t_flag_pair	g_flag_array[] =
{
	{'p', P_FLAG},
	{'q', Q_FLAG},
	{'r', R_FLAG},
	{'s', S_FLAG},
	{'\0', NO_FLAG}
};

struct s_string;
struct s_output_handler;

extern	t_flag_pair g_flag_array[];

typedef struct	s_function_pair
{
	char			*name;
	struct s_string	*(*function)(struct s_output_handler *output_handler, char *);
}				t_function_pair;

struct s_string *crypto_algo_md5   (struct s_output_handler *output_handle, char *args);
struct s_string *crypto_algo_sha256(struct s_output_handler *output_handle, char *args);

# define NULL_CRYPTO_FUNCTION NULL

static t_function_pair g_crypto_dispatch_table[] =
{
	{"md5", &crypto_algo_md5},
	{"sha256", &crypto_algo_sha256},
	{"\0", NULL_CRYPTO_FUNCTION}
};

static t_function_pair g_crypto_dispatch_table[];

#endif
