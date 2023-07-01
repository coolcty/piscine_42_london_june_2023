/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:53:27 by tochen            #+#    #+#             */
/*   Updated: 2023/07/01 15:53:30 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*temp;

	if (!begin_list)
		return ;
	while (begin_list)
	{
		temp = begin_list->next;
		(*free_fct)(begin_list->data);
		free(begin_list);
		begin_list = temp;
	}
}
