/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:23:18 by tochen            #+#    #+#             */
/*   Updated: 2023/06/09 12:23:20 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		ft_putchar('0');
	else if (nb < 0)
	{
		ft_putchar('-');
		if (nb / 10 != 0)
			ft_putnbr(-(nb / 10));
		ft_putchar('0' + nb % 10 + 10);
	}
	else
	{
		if (nb / 10 != 0)
			ft_putnbr(nb / 10);
		ft_putchar(nb % 10);
	}
}
