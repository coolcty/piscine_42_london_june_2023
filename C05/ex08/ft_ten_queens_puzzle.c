/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 01:18:27 by tochen            #+#    #+#             */
/*   Updated: 2023/06/21 01:18:29 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_ok(char *buf, int index)
{
	int	i;

	if (index == -1)
		return (1);
	i = 0;
	while (i < index)
	{
		if (buf[i] == buf[index])
			return (0);
		if (buf[i] - buf[index] == i - index)
			return (0);
		if (buf[i] - buf[index] == index - i)
			return (0);
		i++;
	}
	return (1);
}

void	ft_backtrack(char *buf, int index, int *p_count)
{
	char	q;

	if (index == 9)
	{
		write(1, buf, 11);
		(*p_count)++;
		return ;
	}
	q = '0';
	while (q <= '9')
	{
		buf[index + 1] = q;
		if (ft_check_ok(buf, index + 1))
			ft_backtrack(buf, index + 1, p_count);
		q++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	buf[11];
	int		count;

	buf[10] = '\n';
	count = 0;
	ft_backtrack(buf, -1, &count);
	return (count);
}
