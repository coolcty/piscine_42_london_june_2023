/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:09:05 by tochen            #+#    #+#             */
/*   Updated: 2023/07/04 19:09:07 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	l;
	int	r;

	if (!root)
		return (0);
	l = btree_level_count(root->left);
	r = btree_level_count(root->right);
	if (l > r)
		return (l + 1);
	else
		return (r + 1);
}
