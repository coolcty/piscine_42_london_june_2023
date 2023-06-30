/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:38:35 by tochen            #+#    #+#             */
/*   Updated: 2023/06/29 19:38:37 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	f_add(int n1, int n2)
{
	ft_putnbr(n1 + n2);
}

void	f_div(int n1, int n2)
{
	if (n2 == 0)
	{
		write(1, "Stop : division by zero", 23);
	}
	else
		ft_putnbr(n1 / n2);
}

void	f_mod(int n1, int n2)
{
	if (n2 == 0)
	{
		write(1, "Stop : modulo by zero", 21);
	}
	else
		ft_putnbr(n1 % n2);
}

void	f_sub(int n1, int n2)
{
	ft_putnbr(n1 - n2);
}

void	f_mul(int n1, int n2)
{
	ft_putnbr(n1 * n2);
}
