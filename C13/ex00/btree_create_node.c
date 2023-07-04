/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:49:24 by tochen            #+#    #+#             */
/*   Updated: 2023/07/03 21:49:25 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*result;

	result = malloc(sizeof(t_btree));
	if (!result)
		return (result);
	result->left = 0;
	result->right = 0;
	result->item = item;
	return (result);
}
