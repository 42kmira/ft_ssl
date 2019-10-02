/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:17:24 by kmira             #+#    #+#             */
/*   Updated: 2019/02/18 23:12:40 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int	times_s_has_c(const char *str, char c)
{
	int	i;
	int result;

	i = 0;
	result = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			result++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (result);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		words;
	char	**w;

	i = 0;
	k = 0;
	if (!s || !(w = (char **)malloc(sizeof(*w) * (times_s_has_c(s, c) + 1))))
		return (NULL);
	words = times_s_has_c(s, c);
	while (i < words)
	{
		while (s[k] == c)
			k += 1;
		if (!(w[i] = (char *)malloc(sizeof(char) * (word_len(&s[k], c) + 1))))
			return (NULL);
		j = 0;
		while (s[k] != c && s[k])
			w[i][j++] = s[k++];
		w[i][j] = '\0';
		i += 1;
	}
	w[i] = NULL;
	return (w);
}
