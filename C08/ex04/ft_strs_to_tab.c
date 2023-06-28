/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:53:42 by tochen            #+#    #+#             */
/*   Updated: 2023/06/23 20:53:44 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

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

char	*ft_strcpy(char *dest, char *src)
{
	char	*result;

	result = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (result);
}

struct s_stock_str	ft_create_data(char *str)
{
	struct s_stock_str	data;

	data.size = ft_strlen(str);
	data.str = str;
	data.copy = malloc(sizeof(char) * (data.size + 1));
	if (data.copy)
	{
		ft_strcpy(data.copy, str);
	}
	return (data);
}

void	ft_free_data(struct s_stock_str *result, int i)
{
	while (i > 0)
	{
		free(result[i - 1].copy);
		i--;
	}
	free(result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*result;

	result = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!result)
		return (0);
	result[ac].str = 0;
	i = 0;
	while (i < ac)
	{
		result[i] = ft_create_data(av[i]);
		if (!result[i].copy)
		{
			ft_free_data(result, i - 1);
			return (0);
		}
		i++;
	}
	return (result);
}
