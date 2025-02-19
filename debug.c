/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:49:19 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/19 12:04:03 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void debug_print_list(t_node *stack_n)
{
	while (stack_n != NULL) {
		printf("Node at index %d:\n", stack_n->index);
		printf("  data: %ld\n", stack_n->data);
		printf("  push_cost: %d\n", stack_n->push_cost);
		printf("  median: %s\n", stack_n->median ? "true" : "false");
		printf("  cheapest: %s\n", stack_n->cheapest ? "true" : "false");
		printf("  target: %p\n", (void *)stack_n->target);
		printf("  previous: %p\n", (void *)stack_n->previous);
		printf("  next: %p\n", (void *)stack_n->next);
		stack_n = stack_n->next;
	}
}

void print_linked_list(t_node *lst)
{
	t_node	*tmp_lst;

	tmp_lst = lst;
	while (tmp_lst != NULL)
	{
		ft_printf("Data: %d\n", tmp_lst->data);
		tmp_lst = tmp_lst->next;
	}
}