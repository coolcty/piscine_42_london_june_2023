/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:48:52 by tochen            #+#    #+#             */
/*   Updated: 2023/06/16 19:48:55 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int			l;
	long long	m;
	int			r;

	if (nb <= 0)
		return (0);
	if (nb == 1)
	{
		return (0);
	}
	l = 1;
	r = nb;
	while (l + 1 < r)
	{
		m = (l + r) / 2;
		if (m * m <= nb)
			l = m;
		else
			r = m;
	}
	if (l * l == nb)
		return (l);
	else
		return (0);
}
