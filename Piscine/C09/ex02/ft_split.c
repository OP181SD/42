/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:39:03 by yasaidi           #+#    #+#             */
/*   Updated: 2022/10/03 17:39:05 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_charset(char *charset, char c)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_strsep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !(is_charset(charset, str[i])))
	{
		i++;
	}
	return (i);
}

int	count_word(char *str, char *charset)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && is_charset(charset, str[i]))
		i++;
		if (str[i])
		word++;
		while (str[i] && !is_charset(charset, str[i]))
		i++;
	}
	return (word);
}

char	*ft_strword(char *src, char *charset)
{
	char	*dest;
	int		i;
	int		size;

	size = ft_strsep(src, charset);
	dest = malloc((size + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char		**split;
	int			i;
	int			sizeword;

	sizeword = count_word(str, charset);
	split = malloc(sizeof(char *) * (sizeword + 1));
	if (!(split))
		return (0);
	i = 0;
	split[sizeword] = '\0';
	while (i < sizeword)
	{
		while (str[0] && (is_charset(charset, str[0])))
			str++;
		if (str[0] && (!(is_charset(charset, str[0]))))
		{
			split[i] = ft_strword(str, charset);
			str++;
		}
		while (str[0] && (!(is_charset(charset, str[0]))))
			str++;
		i++;
	}
	return (split);
}
