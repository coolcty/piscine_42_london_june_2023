/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:28:05 by tochen            #+#    #+#             */
/*   Updated: 2023/06/21 22:29:59 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int		ft_strlen(char *str);
int		ft_valid_base(char *str);
int		ft_atoi_base(char *str, char *base);
char	*ft_putnbr_in_buffer_base(int nbr, char *base);

int	ft_nb_len(int nbr, int lbase)
{
	int	i;

	i = (nbr == 0 || nbr < 0);
	while (nbr)
	{
		nbr /= lbase;
		i++;
	}
	return (i);
}

char	*ft_putnbr_in_buffer_base(int nbr, char *base)
{
	int		lbase;
	int		l_nb;
	char	*buffer;
	int		i;

	lbase = ft_strlen(base);
	l_nb = ft_nb_len(nbr, lbase);
	buffer = malloc(sizeof(char) * (l_nb + 1));
	if (!buffer)
		return (buffer);
	buffer[l_nb] = 0;
	buffer[l_nb - 1] = base[(1 - (nbr < 0) * 2) * (nbr % lbase)];
	nbr /= lbase;
	if (nbr < 0)
		buffer[0] = '-';
	i = 2;
	while (nbr)
	{
		buffer[l_nb - i] = base[(1 - (nbr < 0) * 2) * (nbr % lbase)];
		nbr /= lbase;
		i++;
	}
	return (buffer);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!ft_valid_base(base_from) || !ft_valid_base(base_to))
	{
		return (0);
	}
	return (ft_putnbr_in_buffer_base(ft_atoi_base(nbr, base_from), base_to));
}
