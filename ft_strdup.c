/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:00:34 by efournou          #+#    #+#             */
/*   Updated: 2022/04/30 23:58:35 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	size_dst;

	size_dst = ft_strlen(s1) + 1;
	dst = (void *)0;
	if (size_dst == 1)
	{
		dst = (char *)malloc(1);
		*dst = '\0';
		return ((void *)dst);
	}
	dst = (void *)malloc(size_dst);
	if (!dst)
		return ((void *) '\0');
	ft_strlcpy(dst, s1, size_dst);
	return ((void *)dst);
}
