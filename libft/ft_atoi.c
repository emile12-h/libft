/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 22:57:10 by efournou          #+#    #+#             */
/*   Updated: 2022/04/30 23:45:30 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	check_sign(const char *str, int i)
{
	if (str[i] == '+')
		return (1);
	if (str[i] == '-')
		return (-1);
	return (0);
}

int	convert(const char *str, int i)
{
	int	num;
	int	multiplier;
	int	result;

	result = 0;
	num = 0;
	multiplier = 1;
	while (i - 1 >= 0 && str[i - 1] != '-' && str[i - 1] != '+'
		&& ft_isspace(str[i - 1]) != 1)
	{
		num = str[i - 1] - '0';
		result = result + (num * multiplier);
		i--;
		multiplier = multiplier * 10;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	sign = 0;
	result = 0;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	sign = check_sign(str, i);
	if (sign != 0)
		i++;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
		i++;
	result = convert(str, i);
	if (sign == -1)
		return (-result);
	return (result);
}
/*
int	main(void)
{
	char	test[];

    test[] = "     -1234Hello";
    printf("%i", ft_atoi(test));
}
*/