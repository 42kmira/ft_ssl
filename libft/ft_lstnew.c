/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:35:11 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 23:03:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	if (content)
	{
		element->content = malloc(content_size);
		if (element->content)
		{
			ft_memcpy(element->content, content, content_size);
			element->content_size = content_size;
		}
		else
			return (NULL);
	}
	else
	{
		element->content = NULL;
		element->content_size = 0;
	}
	element->next = NULL;
	return (element);
}
