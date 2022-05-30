/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 22:59:29 by efournou          #+#    #+#             */
/*   Updated: 2022/04/30 23:57:12 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	counter;

	counter = 0;
	if (n == 0)
		return (0);
	while ((counter != n
			&& ((unsigned char *)s1)[counter] == ((unsigned char *)s2)[counter]
			&& counter < n - 1))
		counter++;
	return (((unsigned char *)s1)[counter] - ((unsigned char *)s2)[counter]);
}
