/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:36:47 by tochen            #+#    #+#             */
/*   Updated: 2023/06/29 17:36:49 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
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
		while (c > 0 && ft_strcmp(tab[c], tab[c - 1]) < 0)
		{			
			ft_swap_str(tab + c, tab + c - 1);
			c--;
		}
		s++;
	}
}
