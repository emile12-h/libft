/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:19:52 by efournou          #+#    #+#             */
/*   Updated: 2022/05/30 14:37:26 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static void	display_signed_number(long long int a)
{
	char			c;
	long long int	b;
	long long int	d;

	b = 1000000000000000000;
	while (b != 0)
	{
		d = a / b;
		if (d != 0)
		{
			while (b != 0)
			{
				c = ((a / b) % 10) + '0';
				write(1, &c, 1);
				b = b / 10;
			}
		}
		else
		{
			b = b / 10;
		}
	}
}

void	ft_putnbr(long long int nb)
{
	if (nb <= 9223372036854775807 && nb > 0)
		display_signed_number(nb);
	else if (nb < 0)
	{
		write(1, "-", 1);
		display_signed_number(-nb);
	}
	else
		write(1, "0", 1);
}
