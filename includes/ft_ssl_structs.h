/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:36:42 by kmira             #+#    #+#             */
/*   Updated: 2019/10/18 15:00:26 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_STRUCTS_H
# define FT_SSL_STRUCTS_H

# include "ft_ssl_config.h"

typedef struct	s_string
{
	size_t		length;
	char		*string;
	char		free;
}				t_string;

typedef struct	s_output
{
	t_string		*output;
	char			*command;
	enum e_flags	flags;
	int				fd;
	char			*args;
	int				at;
}				t_output;

typedef union	u_512_chunk
{
	uint8_t		str[512];
	u_int32_t	block[16];
}				t_512_chunk;

typedef union	u_converter
{
	u_int32_t	num;
	char		args[4];
}				t_conveter;

typedef union	u_converter_e
{
	u_int64_t	num;
	char		args[8];
}				t_conveter_e;

#endif
