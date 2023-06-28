/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:31:15 by tochen            #+#    #+#             */
/*   Updated: 2023/06/23 21:31:18 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

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
		ft_putchar('0' - (nb % 10));
	}
	else
	{
		if (nb / 10 != 0)
			ft_putnbr(nb / 10);
		ft_putchar('0' + nb % 10);
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par -> str);
		write(1, "\n", 1);
		ft_putnbr(par -> size);
		write(1, "\n", 1);
		ft_putstr(par -> copy);
		write(1, "\n", 1);
		par++;
	}
}
