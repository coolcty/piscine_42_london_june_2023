/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:20:41 by tochen            #+#    #+#             */
/*   Updated: 2023/06/14 20:20:45 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	f;
	int	s;

	while (*str)
	{
		if (*str < ' ' || *str > 126)
		{
			ft_putchar('\\');
			f = (unsigned char)(*str) / 16;
			if (f <= 9)
				ft_putchar('0' + f);
			else
				ft_putchar('a' + f - 10);
			s = (unsigned char)(*str) % 16;
			if (s <= 9)
				ft_putchar('0' + s);
			else
				ft_putchar('a' + s - 10);
		}
		else
		{
			ft_putchar(*str);
		}
		str++;
	}
}
