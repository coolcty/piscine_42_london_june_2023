/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:18:26 by tochen            #+#    #+#             */
/*   Updated: 2023/06/15 09:18:29 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_adress(void *addr)
{
	char				*digit;
	unsigned long long	addrn;
	char				tab[16];
	int					i;

	digit = "0123456789abcdef";
	addrn = (unsigned long long) addr;
	i = 15;
	while (i >= 0)
	{
		tab[i] = digit[addrn % 16];
		addrn /= 16;
		i--;
	}
	write(1, tab, 16);
	write(1, ": ", 2);
}

void	ft_write_hex(char *str, int size)
{
	char	buf[40];
	int		i;
	char	*digit;

	digit = "0123456789abcdef";
	i = 0;
	while (i < 40)
	{
		buf[i] = ' ';
		if (size > 0 && i % 5 != 4)
		{
			buf[i] = digit[(unsigned char)*str / 16];
			buf[i + 1] = digit[(unsigned char)*str % 16];
			i += 2;
			size--;
			str++;
		}
		else
			i++;
	}
	write(1, buf, 40);
}

void	ft_write_str(char *str, int size)
{
	while (size > 0)
	{
		if (*str < ' ' || *str > 126)
			write(1, ".", 1);
		else
			write(1, str, 1);
		str++;
		size--;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*result;

	result = addr;
	while (size > 16)
	{
		ft_print_adress(addr);
		ft_write_hex(addr, 16);
		ft_write_str(addr, 16);
		size -= 16;
		addr += 16;
		write(1, "\n", 1);
	}
	if (size > 0)
	{
		ft_print_adress(addr);
		ft_write_hex(addr, size);
		ft_write_str(addr, size);
		write(1, "\n", 1);
	}
	return (result);
}
