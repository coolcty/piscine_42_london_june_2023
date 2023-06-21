/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 03:33:09 by tochen            #+#    #+#             */
/*   Updated: 2023/06/21 03:33:13 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a ;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_str_tab(char **tab, int size)
{
	int	s;
	int	c;

	s = 0;
	if (size <= 1)
		return ;
	while (s < size - 1)
	{
		c = s + 1;
		while (c > 0 && ft_strcmp(tab[c], tab[c - 1]) < 0)
		{			
			ft_swap_str(tab + c, tab + c - 1);
			c--;
		}
		s++;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++ ;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_sort_str_tab(argv + 1, argc - 1);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
