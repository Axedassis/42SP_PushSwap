/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:29:33 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/23 14:20:15 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	set_cost(t_node **stack_a)
{
	t_node	*cheap_node;
	long	cheapest;
	t_node	*current_node;

	if (!*stack_a)
		return ;
	cheap_node = NULL;
	cheapest = LONG_MAX;
	current_node = *stack_a;
	while (current_node)
	{
		if (current_node->push_cost < cheapest)
		{
			cheap_node = current_node;
			cheapest = current_node->push_cost;
		}
		current_node = current_node->next;
	}
	if (cheap_node)
		cheap_node->cheapest = true;
}

void	analyze_cost(t_node **stack_a, t_node **stack_b)
{
	int		a_size;
	int		b_size;
	t_node	*current_node;

	a_size = get_list_size(*stack_a);
	b_size = get_list_size(*stack_b);
	current_node = *stack_a;
	while (current_node)
	{
		current_node->push_cost = current_node->index;
		if (!(current_node->median))
			current_node->push_cost = a_size - (current_node->index);
		if (current_node->target->median)
			current_node->push_cost += current_node->target->index;
		else
			current_node->push_cost += b_size - (current_node->target->index);
		current_node = current_node->next;
	}
}

void	min_to_top(t_node **stack_n)
{
	while ((*stack_n)->data != get_node_min(*stack_n)->data)
	{
		if (get_node_min(*stack_n)->median)
			ra(stack_n, 1);
		else
			rra(stack_n, 1);
	}
}

void	move_b(t_node **stack_a, t_node **stack_b)
{
	rise_value_a(stack_a, (*stack_b)->target);
	pa(stack_a, stack_b, 1);
}

void	move_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->median && cheapest_node->target->median)
		while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
			rr(stack_a, stack_b, 1);
	else if (!(cheapest_node->median) && !(cheapest_node->target->median))
		while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
			rrr(stack_a, stack_b, 1);
	rise_value_a(stack_a, cheapest_node);
	rise_value_b(stack_b, cheapest_node->target);
	pb(stack_a, stack_b, 1);
}
