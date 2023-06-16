/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:45:35 by tochen            #+#    #+#             */
/*   Updated: 2023/06/16 16:45:36 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result++;
		str++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_pos_nbr_base(long long nb, char *base, int lbase)
{
	if (nb == 0)
		ft_putchar(base[0]);
	else
	{
		if (nb / lbase != 0)
			ft_put_pos_nbr_base(nb / lbase, base, lbase);
		ft_putchar(base[nb % lbase]);
	}
}

int	ft_valid_base(char *str)
{
	char	stat[256];
	int		i;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (i < 256)
	{
		stat[i] = 0;
		i++;
	}
	while (*str)
	{
		if (*str == '+' || *str == '-')
			return (0);
		if (*str == ' ' || (*str <= 13 && *str >= 9))
			return (0);
		if (stat[(unsigned char)*str] == 1)
			return (0);
		stat[(unsigned char)*str] = 1;
		str++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			lbase;
	long long	llnbr;

	if (!ft_valid_base(base))
		return ;
	lbase = ft_strlen(base);
	llnbr = nbr;
	if (llnbr < 0)
	{
		write(1, "-", 1);
		llnbr *= -1;
	}
	ft_put_pos_nbr_base(llnbr, base, lbase);
}
