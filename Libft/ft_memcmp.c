/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:56:58 by yasaidi           #+#    #+#             */
/*   Updated: 2022/11/23 12:41:50 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptrr;

	i = 0;
	ptr = (unsigned char *)s1;
	ptrr = (unsigned char *)s2;
	if (!n)
		return (0);
	while (i < n - 1 && ptr[i] == ptrr[i])
		i++;
	return (ptr[i] - ptrr[i]);
}
