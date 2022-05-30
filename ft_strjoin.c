/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:00:41 by efournou          #+#    #+#             */
/*   Updated: 2022/04/30 23:58:51 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		size;

	size = 0;
	dst = (void *) '\0';
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(size + 1);
	if (dst == (void *) '\0')
		return ((void *) '\0');
	dst[0] = '\0';
	if (dst == (void *) '\0')
		return ((void *) '\0');
	ft_strlcat(dst, s1, size + 1);
	ft_strlcat(dst, s2, size + 1);
	return (dst);
}
