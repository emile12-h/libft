/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:00:07 by efournou          #+#    #+#             */
/*   Updated: 2022/04/30 23:57:42 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	put_recursive(int n, int fd, int nbr_len)
{
	if (nbr_len > 1)
		put_recursive(n / 10, fd, nbr_len - 1);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	put_recursive(n, fd, ft_nbrlen(n));
}

/*
int	main(void)
{
    ft_putnbr_fd(0, 1);
}*/