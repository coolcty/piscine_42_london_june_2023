/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:26:05 by tochen            #+#    #+#             */
/*   Updated: 2023/07/04 09:26:07 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
int (*cmpf)(void *, void *))
{
	t_btree	*tmp;

	if (!root)
		return (0);
	tmp = btree_search_item(root->left, data_ref, cmpf);
	if (tmp)
		return (tmp);
	if ((*cmpf)(data_ref, root->item) == 0)
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}
