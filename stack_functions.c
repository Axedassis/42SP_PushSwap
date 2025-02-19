/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:41:42 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/19 11:50:44 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_node	*create_node(int data, t_node *lst)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node) * 1);
	if (!new_node)
	{
		free_list(lst);
		exit(-1);
	}
	new_node->data = data;
	new_node->index = 0;
	new_node->push_cost = 0;
	new_node->median = false;
	new_node->cheapest = 0;
	new_node->next = NULL;
	new_node->target = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void	push_list(t_node **lst, t_node *new_node)
{
	t_node	*tmp_node;

	if (*lst == NULL)
		*lst = new_node;
	else
	{
		tmp_node = *lst;
		while (tmp_node->next != NULL)
			tmp_node = tmp_node->next;
		tmp_node->next = new_node;
		new_node->previous = tmp_node;
	}
}

void	init_stack(long	*nbrs, t_node **stack_a, int *size)
{
	t_node	*new_node;
	int		i;

	i = 0;
	while (i < *size)
	{
		new_node = create_node(nbrs[i], *stack_a);
		push_list(stack_a, new_node);
		i++;
	}
	update_stack_index(&new_node);
	free(nbrs);
}	
