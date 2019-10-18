/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:14:10 by kmira             #+#    #+#             */
/*   Updated: 2019/10/18 03:29:30 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

void	print_upper(char *command)
{
	int		i;
	char	*print;

	i = 0;
	print = ft_strdup(command);
	while (print[i] != '\0')
	{
		if (ft_islower(print[i]))
			print[i] += ('A' - 'a');
		i++;
	}
	write(1, print, ft_strlen(print));
	write(1, " ("BOLDBLUE, 12);
	free(print);
}

void	print_output(t_output *output_handler, t_string *digest, char *args)
{
	if ((output_handler->flags & Q_FLAG) == 0 && (output_handler->flags
	& R_FLAG) == 0 && (output_handler->flags & P_FLAG) == 0)
	{
		print_upper(output_handler->command);
		if (output_handler->flags & S_FLAG)
			write(1, COLOR_RESET"\""BOLDCYAN, 15);
		write(1, args, ft_strlen(args));
		if (output_handler->flags & S_FLAG)
			write(1, COLOR_RESET"\"", 6);
		write(1, COLOR_RESET") = ", 9);
	}
	write(1, BOLDMAGENTA"", 10);
	write(1, digest->string, digest->length);
	if (output_handler->flags & R_FLAG && (output_handler->flags & P_FLAG) == 0)
	{
		write(1, COLOR_RESET" "BOLDBLUE, 15);
		if (output_handler->flags & S_FLAG)
			write(1, COLOR_RESET"\""BOLDCYAN, 15);
		write(1, args, ft_strlen(args));
		if (output_handler->flags & S_FLAG)
			write(1, COLOR_RESET"\"", 6);
	}
	write(1, COLOR_RESET"\n", 6);
	free(digest->string);
	free(digest);
}

void	print_usage_error(void)
{
	ft_puterror("usage: ft_ssl command [command opts] [command args]");
}

void	print_wrong_command(char *arg)
{
	write(1, "ft_ssl: Error: '", 17);
	write(1, arg, ft_strlen(arg));
	write(1, "' is an invalid command.\n\nStandard comman", 42);
	write(1, "ds:\n\nMessage Digest commands:\nmd5\nsha256\n", 42);
	ft_puterror("");
}

void	print_file_err(char *file_name, char *command)
{
	write(1, "ft_ssl: ", 9);
	write(1, command, ft_strlen(command));
	write(1, ": ", 2);
	if (errno == EISDIR)
	{
		write(1, file_name, ft_strlen(file_name));
		write(1, ": Is a directory\n", 18);
	}
	else if (errno == EACCES)
	{
		write(1, file_name, ft_strlen(file_name));
		write(1, ": Permission denied\n", 21);
	}
	else if (errno == ENOENT)
	{
		write(1, file_name, ft_strlen(file_name));
		write(1, ": No such file or directory\n", 29);
	}
	errno = 0;
}
