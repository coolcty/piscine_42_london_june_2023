/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:53:42 by tochen            #+#    #+#             */
/*   Updated: 2023/07/04 19:53:43 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	**create_level_nodes(int level_size, t_btree **curr_level)
{
	t_btree	**level_nodes;

	level_nodes = malloc(sizeof(t_btree *) * (level_size + 1));
	if (!level_nodes)
	{
		free(curr_level);
		return (0);
	}
	return (level_nodes);
}

void	process_current_level(t_btree **curr_level, t_btree **next_level
, void (*applyf
)(void *item, int current_level, int is_first_elem), int level, int *pos_n)
{
	int	pos;

	pos = 0;
	while (curr_level[pos])
	{
		(*applyf)(curr_level[pos]->item, level, pos == 0);
		if (curr_level[pos]->left)
		{
			next_level[*pos_n] = curr_level[pos]->left;
			(*pos_n)++;
		}
		if (curr_level[pos]->right)
		{
			next_level[*pos_n] = curr_level[pos]->right;
			(*pos_n)++;
		}
		pos++;
	}
	next_level[*pos_n] = 0;
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void
*item, int current_level, int is_first_elem))
{
	t_btree	**curr_level;
	t_btree	**next_level;
	int		level;
	int		pos_n;

	curr_level = create_level_nodes(2, 0);
	if (!curr_level)
		return ;
	curr_level[0] = root;
	curr_level[1] = 0;
	level = 0;
	while (curr_level[0])
	{
		pos_n = 0;
		next_level = create_level_nodes((1 << (level + 1)), curr_level);
		if (!next_level)
			return ;
		process_current_level(curr_level, next_level, applyf, level, &pos_n);
		free(curr_level);
		curr_level = next_level;
		level++;
	}
	free(curr_level);
}
