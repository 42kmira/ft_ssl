/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:04:10 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:12:25 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Change to version like ft_strcmp.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	if (!(s) || !(f))
		return ;
	i = 0;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}
