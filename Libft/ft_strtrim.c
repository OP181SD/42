/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:44:47 by yasaidi           #+#    #+#             */
/*   Updated: 2022/11/25 16:16:02 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iset(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	remove_trim(char *tab, char const *s1, int *i, int *j)
{
	*tab = *s1;
	(*i)++;
	(*j)++;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*tab;

	i = 0;
	while (ft_iset(set, s1[i]))
		i++;
	if (i == (int)ft_strlen(s1))
		return (tab = malloc(1), tab[0] = '\0', tab);
	k = ft_strlen(s1) - 1;
	while (ft_iset(set, s1[k]))
		k--;
	k++;
	tab = malloc((k - i + 1) * sizeof(char));
	if (!tab)
		return (0);
	j = 0;
	while (i < k)
		remove_trim(tab + j, s1 + i, &i, &j);
	tab[j] = '\0';
	return (tab);
}
/*
int main()
{
	char *s;
	s = ft_strtrim("123", "");
	 return 0;
}
*/