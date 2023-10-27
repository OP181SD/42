/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:04:48 by yasaidi           #+#    #+#             */
/*   Updated: 2022/11/28 11:04:50 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size > 0)
	{
		while (src[i] && (i < size - 1))
		{	
			dest[i] = src[i];
			i++;
		}	
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
