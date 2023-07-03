/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 02:19:40 by tochen            #+#    #+#             */
/*   Updated: 2023/07/03 02:19:42 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1,
t_list *begin_list2, int (*cmp)())
{
	if (!(*begin_list1))
	{
		*begin_list1 = begin_list2;
		return ;
	}
	if (!begin_list2)
		return ;
	if ((*cmp)((*begin_list1)->data, begin_list2->data) < 0)
	{
		ft_sorted_list_merge(&((*begin_list1)->next), begin_list2, cmp);
	}
	else
	{
		ft_sorted_list_merge(begin_list1, begin_list2->next, cmp);
		begin_list2->next = *begin_list1;
		*begin_list1 = begin_list2;
	}
}
