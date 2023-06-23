/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:25:29 by tochen            #+#    #+#             */
/*   Updated: 2023/06/21 15:25:31 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	if (min >= max)
		return (0);
	result = malloc(sizeof(int) * (max - min));
	if (!result)
		return (0);
	i = min;
	while (i < max)
	{
		result[i - min] = i;
		i++;
	}
	return (result);
}
