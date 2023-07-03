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

	if (size == 0)
		return (0);
	begin_list = ft_create_elem(strs[size - 1]);
	size--;
	curr_list = begin_list;
	while (size)
	{
		curr_list->next = ft_create_elem(strs[size - 1]);
		curr_list = curr_list->next;
		size--;
	}
	return (begin_list);
}
