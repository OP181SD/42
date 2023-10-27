/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:33:28 by yasaidi           #+#    #+#             */
/*   Updated: 2022/11/28 14:02:53 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	sub_len(const char *s, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start + i] && i < len)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*tab;
	unsigned int		i;
	unsigned int		j;
	unsigned int		s_len;

	if (start > (unsigned int)ft_strlen(s))
		return (tab = malloc(1), tab[0] = '\0', tab);
	s_len = sub_len(s, (size_t)start, len);
	tab = (char *)malloc(s_len + 1 * sizeof(char));
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (s[start + i] && j < len)
	{
		tab[j] = s[i + start];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}
