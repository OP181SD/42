/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:28:20 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 19:08:34 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	int	res;

	res = write(fd, &c, 1);
	if (res == -1)
	{
		ft_putstr_fd("minishell: write error: no space left on device\n", 2);
		return (-1);
	}
	return (0);
}
