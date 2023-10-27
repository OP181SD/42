/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:27:30 by yasaidi           #+#    #+#             */
/*   Updated: 2023/05/21 13:45:26 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static size_t	ft_strnlen(const char *str, size_t n, size_t len)
{
	size_t	i;

	i = 0;
	while (str[n + i] && i < len)
		i++;
	return (i);
}

static char	*ft_strnword(char *dest, const char *src, size_t n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < n)
		i++;
	while (src[i] && j < len)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start > (unsigned int)ft_strlen(s))
		return (str = malloc(1), str[0] = '\0', str);
	str = ((char *)malloc(sizeof(char) * ft_strnlen(s, (size_t)start, len)
				+ 1));
	if (!str)
		return (NULL);
	ft_strnword(str, s, start, len);
	return (str);
}
