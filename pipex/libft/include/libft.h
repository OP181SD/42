/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:58:49 by yasaidi           #+#    #+#             */
/*   Updated: 2023/06/12 22:29:47 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// bool.h
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isascii(int c);
int		ft_isalnum(char c);
int		ft_isspace(char c);
// strings.h
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strnstr(const char *str, const char *little, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strncpy(char *dst, char *src, size_t len);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
void	*ft_memchr(const void *mb, int c, size_t size);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *mb, int c, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strtrim(const char *s1, const char *set);
// ctypes.h
int		ft_toupper(int c);
int		ft_tolower(int c);
// stdlib.h
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
void	ft_swap(int *a, int *b);

#endif