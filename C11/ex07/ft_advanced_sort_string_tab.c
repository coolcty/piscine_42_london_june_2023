/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:42:07 by tochen            #+#    #+#             */
/*   Updated: 2023/06/29 17:42:09 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_str_tab_len(char **tab)
{
	int	result;

	result = 0;
	while (*tab)
	{
		result++;
		tab++;
	}
	return (result);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	s;
	int	c;
	int	size;

	size = ft_str_tab_len(tab);
	s = 0;
	if (size <= 1)
		return ;
	while (s < size - 1)
	{
		c = s + 1;
		while (c > 0 && (*cmp)(tab[c], tab[c - 1]) < 0)
		{
			ft_swap_str(tab + c, tab + c - 1);
			c--;
		}
		s++;
	}
}
