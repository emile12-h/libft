/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:01:10 by efournou          #+#    #+#             */
/*   Updated: 2022/04/30 23:59:59 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*j;

	j = (char *) '\0';
	i = 0;
	if (ft_isascii(c) == 0)
		c = c - 256;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (j);
}
