/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:29:33 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/14 16:09:56 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	cost_set(s_node **stack_a)
{
	s_node	*tmp_node;
	s_node	*cheap_node;
	long	cheapest;

	tmp_node = *stack_a;
	if (!tmp_node)
		return ;
	cheap_node = NULL;
	cheapest = LONG_MAX;
	while (tmp_node)
	{
		if (tmp_node->push_cost < cheapest)
		{
			cheap_node = tmp_node;
			cheapest = tmp_node->push_cost;
		}
		tmp_node = tmp_node->next;
	}
	if (cheap_node)
		cheap_node->cheapest = true;
}

void	cost_analysis(s_node **stack_a, s_node **stack_b)
{
	s_node	*tmp_stack;
	int		a_size;
	int		b_size;

	tmp_stack = *stack_a;
	a_size = size_list(*stack_a);
	b_size = size_list(*stack_b);

	while (tmp_stack)
	{
		tmp_stack->push_cost = tmp_stack->index;
		if (!(tmp_stack->median))
			tmp_stack->push_cost = a_size - (tmp_stack->index);
		if (tmp_stack->target->median)
			tmp_stack->push_cost += tmp_stack->target->index;
		else
			tmp_stack->push_cost += b_size - (tmp_stack->target->index);
		tmp_stack = tmp_stack->next;
	}
}

void	min_to_top(s_node **stack_n)
{
	while ((*stack_n)->data != node_min(*stack_n)->data)
	{
		if(node_min(*stack_n)->median)
			ra(stack_n, 1);
		else
			rra(stack_n, 1);
	}
}

void	rise_value(s_node **stack_n, s_node *target, char stack_l)
{
	while (*stack_n != target)
	{
		if (stack_l == 'a')
		{
			if (target->median)
				ra(stack_n, 1);
			else
				rra(stack_n, 1);
		}
		else if (stack_l == 'b')
		{
			if (target->median)
				rb(stack_n, 1);
			else
				rrb(stack_n, 1);
		}	
	}
}

// void	rise_value_A(s_node **stack_a, s_node *target)
// {
// 	while (*stack_a != target)
// 	{
// 		if (target->median)
// 			ra(stack_a, 1);
// 		else
// 			rra(stack_a, 1);
// 	}
// }

// void	rise_value_B(s_node **stack_b, s_node *target)
// {
// 	while (*stack_b != target)
// 	{
// 		if (target->median)
// 			rb(stack_b, 1);
// 		else
// 			rrb(stack_b, 1);
// 	}
// }

void move_b(s_node **stack_a, s_node **stack_b)
{
	rise_value(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b, 1);
}

void move_a(s_node **stack_a, s_node **stack_b)
{
	s_node	*cheapest_node;

	cheapest_node = find_cheapest(*stack_a);
	if (cheapest_node->median && cheapest_node->target->median)
		while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
			rr(stack_a, stack_b);
	else if (!(cheapest_node->median) && !(cheapest_node->target->median))
		while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
			rrr(stack_a, stack_b);
	update_index(stack_a);
	update_index(stack_b);
	rise_value(stack_a, cheapest_node, 'a');
	rise_value(stack_b, cheapest_node->target, 'b');
	pb(stack_a, stack_b, 1);
}