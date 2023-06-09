/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:45:42 by tochen            #+#    #+#             */
/*   Updated: 2023/06/09 12:45:44 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_comb(char *buf, int index, int n)
{
	char	c;

	if (index == (n - 1))
	{
		write(1, buf, n);
		if (buf[0] != '9' - n + 1)
			write(1, ", ", 2);
		return ;
	}
	c = buf[index] + 1;
	while (c <= '9')
	{
		buf[index + 1] = c;
		write_comb(buf, index + 1, n);
		c++;
	}
}

void	ft_print_combn(int n)
{
	char	buf[10];
	char	c;

	c = '0';
	while (c <= '9')
	{
		buf[9] = c;
		write_comb(buf, 0, n);
		c++;
	}
}
