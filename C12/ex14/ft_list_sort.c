/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:54:43 by tochen            #+#    #+#             */
/*   Updated: 2023/07/01 15:54:45 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	head;
	t_list	*curr;
	t_list	*pos;
	t_list	*tmp1;
	t_list	*tmp2;

	head.next = 0;
	curr = *begin_list;
	while (curr)
	{
		pos = &head;
		while (pos->next && (*cmp)(curr->data, pos->next->data) > 0)
		{
			pos = pos->next;
		}
		tmp1 = pos->next;
		pos->next = curr;
		tmp2 = curr->next;
		curr->next = tmp1;
		curr = tmp2;
	}
	*begin_list = head.next;
}
