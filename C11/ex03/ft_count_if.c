/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:10:27 by tochen            #+#    #+#             */
/*   Updated: 2023/06/29 16:10:28 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	result;

	result = 0;
	if (!tab)
		return (0);
	while ((length--) > 0)
	{
		if ((*f)(*tab))
			result++;
		tab++;
	}
	return (result);
}
