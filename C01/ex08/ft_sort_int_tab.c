/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:14:51 by tochen            #+#    #+#             */
/*   Updated: 2023/06/14 17:14:54 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a ;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	s;
	int	c;

	s = 0;
	if (size <= 1)
		return ;
	while (s < size - 1)
	{
		c = s + 1;
		while (c > 0 && tab[c] < tab[c - 1])
		{			
			ft_swap(tab + c, tab + c - 1);
			c--;
		}
		s++;
	}
}
