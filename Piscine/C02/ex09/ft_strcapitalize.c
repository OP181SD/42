/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:54:10 by yasaidi           #+#    #+#             */
/*   Updated: 2022/09/17 23:54:11 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_alpha_numeric(char c)
{
	if (!(c >= 'a' && c <= 'z')
		&& !(c >= 'A' && c <= 'Z')
		&& !(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	ft_str_is_uppercase(char c)
{
	if (!(c >= 'A' && c <= 'Z'))
		return (0);
	return (1);
}

int	ft_str_is_lowercase(char c)
{
	if (!(c >= 'a' && c <= 'z'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_str_is_alpha_numeric(str[i - 1]))
		{
			if (ft_str_is_uppercase(str[i]))
					str[i] += 32;
		}
		else if (!ft_str_is_alpha_numeric(str[i - 1]))
		{
			if (ft_str_is_lowercase(str[i]))
					str[i] -= 32;
		}
			i++;
	}
	return (str);
}
