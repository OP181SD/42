/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:23:35 by yasaidi           #+#    #+#             */
/*   Updated: 2022/09/19 19:23:36 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (src[size])
	{
		size++;
	}
	
	src[i] = '\0';
	return (i);
}

#include <bsd/string.h>
#include <stdio.h>

int main(void)
{
	char dest[] = "yassine";
	char dest2[] = "yassine";
	char dest3[] = "yassine";
	char dest4[] = "yassine";
	char dest5[] = "yassine";
	char dest6[] = "yassine";
	char src[] = "valentinlebgdefou";

	printf("%d\n",ft_strlcpy(dest, src, 8));
	printf("%s\n", dest);
	printf("%s\n", src);
	printf("%d\n",ft_strlcpy(dest2, src, 6));
	printf("%s\n", dest2);
	printf("%ld\n",strlcpy(dest5,src,3));
	printf("%s\n", dest5);
	printf("STRLCPY\n");
	printf("%ld\n",strlcpy(dest3,src,8));
	printf("%s\n", dest3);
	printf("%s\n", src);
	printf("%ld\n",strlcpy(dest4,src,6));
	printf("%s\n", dest4);
	printf("%ld\n",strlcpy(dest6,src,3));
	printf("%s\n", dest6);

}