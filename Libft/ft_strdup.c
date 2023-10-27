/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:38:04 by yasaidi           #+#    #+#             */
/*   Updated: 2022/11/23 19:39:15 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	dest = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (s[i])
	{
		((char *)dest)[i] = s[i];
		i++;
	}
	((char *)dest)[i] = '\0';
	return ((char *)dest);
}
