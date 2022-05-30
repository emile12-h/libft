/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:00:27 by efournou          #+#    #+#             */
/*   Updated: 2022/05/01 00:02:55 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_strlen_c(const char *s, char c, size_t i)
{
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static int	detect_char(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_count_world(const char *s, char c)
{
	size_t	i;
	size_t	result;

	result = 1;
	i = 0;
	if (c == '\0')
		return (result);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			i--;
			result++;
		}
		i++;
	}
	if (s[0] == c)
		result--;
	if (s[i - 1] == c)
		result--;
	if (result == 0 && detect_char(s, c) == 1)
		result = 1;
	return (result);
}

char	**fill_array(char **dst, char const *s, size_t i, char c)
{
	size_t	j;

	j = 0;
	while (s[i] != '\0')
	{
		dst[j] = ft_substr(s, i, ft_strlen_c(s, c, i) - i);
		if (!dst[j])
		{
			while (j >= 0)
			{
				free(dst[j]);
				j--;
			}
			free(dst);
			return ((void *) '\0');
		}
		i = ft_strlen_c(s, c, i);
		while (s[i] == c && c != '\0')
			i++;
		j++;
	}
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	i;

	dst = (void *) '\0';
	i = 0;
	if (!s)
		return ((void *) '\0');
	dst = (char **)ft_calloc((ft_count_world(s, c) + 1), sizeof(char *));
	if (dst == (void *) '\0')
		return ((void *) '\0');
	if (s[0] == '\0')
	{
		dst[0] = (void *) '\0';
		return (dst);
	}
	while (s[i] == c)
		i++;
	dst = fill_array(dst, s, i, c);
	if (!dst)
		return ((void *) '\0');
	return (dst);
}

/*
int	main(void)
{
	char	str[];
	char	c;
	int		i;

    str[] = "      split       this for   me  !       ";
    c = ' ';
    char ** result = ft_split(str,c);
    i = 0;
    while (i <= 5)
    {
        printf("\n%s", result[i]);
        i++;
    }
}
*/