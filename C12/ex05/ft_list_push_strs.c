/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:53:06 by tochen            #+#    #+#             */
/*   Updated: 2023/07/01 15:53:12 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin_list;
	t_list	*curr_list;
	int		i;

	if (size == 0)
		return (0);
	begin_list = ft_create_elem(strs[0]);
	curr_list = begin_list;
	i = 1;
	while (i < size)
	{
		curr_list->next = ft_create_elem(strs[i]);
		curr_list = curr_list->next;
		i++;
	}
	return (begin_list);
}
