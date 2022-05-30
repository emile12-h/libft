/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:01:38 by efournou          #+#    #+#             */
/*   Updated: 2022/05/01 00:00:42 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		size;

	dst = (void *) '\0';
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dst = (char *)malloc(1);
		if (!dst)
			return (NULL);
		*dst = '\0';
		return (dst);
	}
	if (ft_strlen(&(s[start])) < len)
		size = ft_strlen(&(s[start]));
	else
		size = len;
	dst = (char *)malloc(size + 1);
	if (dst == (void *) '\0')
		return ((void *) '\0');
	ft_strlcpy(dst, &(s[start]), size + 1);
	return (dst);
}
