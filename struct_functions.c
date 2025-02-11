/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:41:42 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/11 12:13:26 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

s_node	*create_node(int data, s_node *lst)
{
	s_node	*new_node;

	new_node = (s_node *)malloc(sizeof(s_node) * 1);
	if (!new_node)
	{
		free_list(lst);
		exit(-1);
	}
	new_node->data = data;
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->target = NULL;
	new_node->cheapest = 0;
	new_node->push_cost = 0;
	return (new_node);
}

void	push_list(s_node **lst, s_node *new_node)
{
	s_node	*tmp_node;

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

void	init_stack(int	*nbrs, s_node **stack_a)
{
	s_node	*new_node;
	int		i;

	i = 0;
	while (nbrs[i])
	{
		new_node = create_node(nbrs[i], *stack_a);
		push_list(stack_a, new_node);
		i++;
	}
}	
