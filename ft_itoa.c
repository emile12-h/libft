/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 22:58:46 by efournou          #+#    #+#             */
/*   Updated: 2022/04/30 23:47:03 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nbrlen(int n)
{
	long int	result;
	long int	divider;
	long int	test;

	test = 1;
	result = 0;
	divider = 10;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = -n;
	while (test > 0)
	{
		test = n / divider;
		divider = divider * 10;
		result++;
	}
	return (result);
}

static void	fill_string(char *result, int i, int n, int convert)
{
	if (n == 0)
		result[0] = '0';
	while (i >= 0 && result[i] != '-')
	{
		result[i] = ((n % 10) * convert) + '0';
		n = n / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		convert;

	result = (void *) '\0';
	convert = 1;
	i = ft_nbrlen(n);
	if (n < 0)
	{
		result = (char *)ft_calloc(i + 2, 1);
		if (!result)
			return ((void *) '\0');
		result[0] = '-';
		convert = -1;
	}
	else
	{
		result = (char *)ft_calloc(i + 1, 1);
		if (!result)
			return ((void *) '\0');
		i--;
	}
	fill_string(result, i, n, convert);
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
    int i = -2147483648;
    while(i != 2147483647)
    {
        printf("\n%s", ft_itoa(i));
        i++;    
    }
}*/