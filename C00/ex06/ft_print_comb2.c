/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:52:28 by tochen            #+#    #+#             */
/*   Updated: 2023/06/09 11:52:30 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_2_digits_natural_number(int n)
{
	ft_putchar('0' + n / 10);
	ft_putchar('0' + n % 10);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_write_2_digits_natural_number(i);
			ft_putchar(' ');
			ft_write_2_digits_natural_number(j);
			if (i != 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
