/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 22:59:25 by efournou          #+#    #+#             */
/*   Updated: 2022/04/30 23:56:12 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ((void *)0);
	while (i != n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&(((void *)s)[i]));
		i++;
	}
	if (c == '\0')
		return (&(((void *)s)[i]));
	return ((void *)0);
}
