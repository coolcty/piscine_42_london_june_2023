/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:37:25 by tochen            #+#    #+#             */
/*   Updated: 2023/06/29 19:37:29 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "do_op.h"

int	ft_find_index(char c)
{
	if (c == '+')
		return (0);
	if (c == '-')
		return (1);
	if (c == '/')
		return (2);
	if (c == '*')
		return (3);
	if (c == '%')
		return (4);
	return (-1);
}

void	ft_op(int n1, char op, int n2)
{
	void	(*f[5])(int, int);

	f[0] = &f_add;
	f[1] = &f_sub;
	f[2] = &f_div;
	f[3] = &f_mul;
	f[4] = &f_mod;
	(*(f[ft_find_index(op)]))(n1, n2);
	write(1, "\n", 1);
}
