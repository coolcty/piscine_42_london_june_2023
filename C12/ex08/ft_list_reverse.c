/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:39:10 by tochen            #+#    #+#             */
/*   Updated: 2023/07/02 10:39:13 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*l;
	t_list	*tmp;
	t_list	*r;

	if (!(*begin_list) || !((*begin_list)->next))
		return ;
	l = *begin_list;
	r = l->next;
	l->next = 0;
	while (r)
	{
		tmp = r->next;
		r->next = l;
		l = r;
		r = tmp;
	}
	*begin_list = l;
}
