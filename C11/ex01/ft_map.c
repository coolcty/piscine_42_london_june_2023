/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:43:10 by tochen            #+#    #+#             */
/*   Updated: 2023/06/29 15:43:13 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*result;

	result = malloc(sizeof(int) * (length));
	if (!result)
		return (result);
	i = -1;
	while ((++i) < length)
		result[i] = (*f)(tab[i]);
	return (result);
}
