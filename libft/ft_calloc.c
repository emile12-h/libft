/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 22:57:35 by efournou          #+#    #+#             */
/*   Updated: 2022/04/30 23:46:21 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	size_alloc;

	size_alloc = 0;
	ptr = (void *) '\0';
	i = 0;
	if (size == 0)
		size++;
	if (count == 0)
		count++;
	size_alloc = count * size;
	if (size_alloc < count || size_alloc < size)
		return ((void *) '\0');
	ptr = (char *)malloc(size_alloc);
	if (ptr == (void *) '\0' && size_alloc > 0)
		return ((void *) '\0');
	while (i != size_alloc)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

/*#include <stdio.h>
int	main(void)
{
    printf("%p", ft_calloc(2147483647, 2147483647));
}*/