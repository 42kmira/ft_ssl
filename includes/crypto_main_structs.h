/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypto_main_structs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 22:03:58 by kmira             #+#    #+#             */
/*   Updated: 2019/10/02 23:54:01 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRYPTO_MAIN_STRUCTS_H
# define CRYPTO_MAIN_STRUCTS_H

// • -p, echo STDIN to STDOUT and append the checksum to STDOUT
// • -q, quiet mode
// • -r, reverse the format of the output.
// • -s, print the sum of the given string

typedef struct	s_string
{
	size_t		length;
	char		*string;
	char		free;
}				t_string;

enum e_flags
{
    P_FLAG  = 0b00001,
    Q_FLAG  = 0b00010,
    R_FLAG  = 0b00100,
    S_FLAG  = 0b01000,
    NO_FLAG = 0b10000
};

typedef struct	s_flag_pair
{
	enum e_flags	flag_value;
	int				pair;
}				t_flag_pair;

typedef struct	s_output_handler
{
	t_string		*output;
	enum e_flags	flags;
}				t_output_handler;

typedef struct	s_function_pair
{
	char			*name;
	t_string		*(*function)(t_output_handler *output_handler, char **, int *);
}				t_function_pair;

typedef union	u_crypto_functions
{
	t_string	(*function_md5)(t_output_handler *, char **, int *);
	t_string	(*function_sha256)(t_output_handler *, char **, int *);
}				t_crypto_funtions;

#endif
