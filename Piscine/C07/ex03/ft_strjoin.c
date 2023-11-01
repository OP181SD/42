/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:00:14 by yasaidi           #+#    #+#             */
/*   Updated: 2022/09/28 11:00:15 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = '\0';
	return (dest);
}

int	ft_len(char **str, int size, char *sep)
{
	int	i;
	int	len;

	if (size == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		len = len + ft_strlen(str[i]);
		i++;
	}
	len = len + (size - 1) * ft_strlen(sep);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (1 + ft_len(strs, size, sep)));
	if (str == NULL)
		return (NULL);
	i = 0;
	str[0] = '\0';
	if (size)
	{
		while (i < size)
		{
			ft_strcat(str, strs[i]);
			if (i < size - 1)
			{
				ft_strcat(str, sep);
			}
			i++;
		}
		str[ft_len(strs, size, sep)] = '\0';
	}
	return (str);
}
