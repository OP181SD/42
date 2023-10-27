/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:34:55 by yasaidi           #+#    #+#             */
/*   Updated: 2022/11/23 11:57:04 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	if (size == 0 && (!src || !dest))
		return (0);
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if (size < len_dest)
		return (len_src + size);
	while (src[i] && (len_dest + i + 1) < size)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[i + len_dest] = '\0';
	return (len_dest + len_src);
}
