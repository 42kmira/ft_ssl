/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypto_main_structs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 22:03:58 by kmira             #+#    #+#             */
/*   Updated: 2019/10/02 00:12:50 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRYPTO_MAIN_STRUCTS_H
# define CRYPTO_MAIN_STRUCTS_H

// • -p, echo STDIN to STDOUT and append the checksum to STDOUT
// • -q, quiet mode
// • -r, reverse the format of the output.
// • -s, print the sum of the given string

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
	int				a;
	enum e_flags	flag_value;
}				t_flag_pair;


typedef struct	s_string
{
	size_t		length;
	char		*string;
	char		free;
}				t_string;

typedef union	u_crypto_functions
{
	t_string	(*function_md5)(void);
	t_string	(*function_sha256)(void);
}				t_crypto_funtions;

#endif
