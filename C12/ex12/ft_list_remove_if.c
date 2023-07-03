/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:21:50 by tochen            #+#    #+#             */
/*   Updated: 2023/07/02 16:22:07 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *))
{
	t_list	head;
	t_list	*curr;
	t_list	*pre;

	head.next = *begin_list;
	pre = &head;
	curr = pre->next;
	while (curr)
	{
		if ((*cmp)(curr->data, data_ref) == 0)
		{
			(*free_fct)(curr->data);
			pre->next = curr->next;
			free(curr);
			break ;
		}
		pre = curr;
		curr = curr->next;
	}
	*begin_list = head.next;
}
