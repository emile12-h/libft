/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:01:34 by efournou          #+#    #+#             */
/*   Updated: 2022/05/01 01:18:03 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (ft_strchr(set, s1[i]) != (char *) '\0')
		i++;
	return (i);
}

static int	find_end(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) != (char *) '\0' && i >= 0)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	int				size;
	char			*dst;

	if (s1 == (void *) '\0' || set == (void *) '\0')
		return ((void *) '\0');
	start = 0;
	end = 0;
	size = 0;
	dst = (void *) '\0';
	start = find_start(s1, set);
	end = find_end(s1, set);
	size = end - start + 1;
	dst = ft_substr(s1, start, size);
	return (dst);
}
