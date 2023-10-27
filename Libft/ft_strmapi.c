/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:53:29 by yasaidi           #+#    #+#             */
/*   Updated: 2022/11/23 11:59:32 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	str = (char *) malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

//char	add_i(unsigned int i, char c)
//{
//	return (i + c);
//}
//int	main(void)
//{
//	char str[] = "yassine";
//	printf("%s",ft_strmapi(str, add_i));
//}