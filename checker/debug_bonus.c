/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:49:19 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/23 14:20:29 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	debug_print_list(t_node *stack_n)
{
	while (stack_n != NULL)
	{
		ft_printf("Node at index %d:\n", stack_n->index);
		ft_printf("  data: %ld\n", stack_n->data);
		ft_printf("  push_cost: %d\n", stack_n->push_cost);
		if (stack_n->median)
			ft_printf("  median: true\n");
		else
			ft_printf("  median: false\n");
		if (stack_n->cheapest)
			ft_printf("  cheapest: true\n");
		else
			ft_printf("  cheapest: false\n");
		ft_printf("  target: %p\n", (void *)stack_n->target);
		ft_printf("  previous: %p\n", (void *)stack_n->previous);
		ft_printf("  next: %p\n", (void *)stack_n->next);
		stack_n = stack_n->next;
	}
}

void	print_linked_list(t_node *lst)
{
	t_node	*tmp_lst;

	tmp_lst = lst;
	while (tmp_lst != NULL)
	{
		ft_printf("Data: %d\n", tmp_lst->data);
		tmp_lst = tmp_lst->next;
	}
}
