/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:20:05 by yasaidi           #+#    #+#             */
/*   Updated: 2022/11/29 17:58:30 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size > 0 && nmemb * size / size != nmemb)
		return (NULL);
	tab = (char *) malloc(nmemb * size);
	if (!tab)
		return (0);
	ft_bzero (tab, size * nmemb);
	return (tab);
}
