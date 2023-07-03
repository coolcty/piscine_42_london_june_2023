/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 01:48:16 by tochen            #+#    #+#             */
/*   Updated: 2023/07/03 01:48:18 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	header;
	t_list	*curr;
	t_list	*tmp1;
	t_list	*pos;

	curr = ft_create_elem(data);
	header.next = *begin_list;
	pos = &header;
	while (pos->next && (*cmp)(curr->data, pos->next->data) > 0)
		pos = pos->next;
	tmp1 = pos->next;
	pos->next = curr;
	curr->next = tmp1;
	*begin_list = header.next;
}
