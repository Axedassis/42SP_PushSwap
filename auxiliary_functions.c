/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:29:33 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/13 17:10:35 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	cost_set(s_node **stack_a)
{
	s_node	*tmp_node;
	s_node	*cheap_node;
	long	cheapest;

	tmp_node = *stack_a;
	cheapest = LONG_MAX;
	while (tmp_node)
	{
		if (tmp_node->push_cost < cheapest)
		{
			cheap_node = tmp_node;
			cheapest =  tmp_node->push_cost;
		}
		tmp_node = tmp_node->next;
	}
}

	/*
	push cost start being the node index
	
	The main idea is to verify whether the target node from stacks A and B is
	above or below the median line.

	If it is above, it is better to use ra(), which moves the current node to
	the top of the stack.

	If it is below, it is more efficient to use rra(), which moves the node from 
	its current position to the top by reversing the stack. This is calculated as
	the difference between the current node and the first node: len_a(b) - crr.index

	the same for the target stack!
	*/

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

		if (!tmp_stack->median)
			tmp_stack->push_cost = a_size - tmp_stack->index;
		if (tmp_stack->target->median)
			tmp_stack->push_cost += tmp_stack->target->index;
		else
			tmp_stack->push_cost += b_size - tmp_stack->target->index;
		tmp_stack = tmp_stack->next;
	}
}

void	min_to_top(s_node **stack_n)
{
	while ((*stack_n)->data != node_min(*stack_n)->data)
	{
		if(node_min(*stack_n)->median)
			ra(stack_n);
		else
			rra(stack_n);
	}
}

void	rise_value_A(s_node **stack_a, s_node *target)
{
	s_node	*tmp_ptr;

	tmp_ptr = *stack_a;
	while (*stack_a != target)
	{
		if (target->median)
			ra(stack_a);
		if (!target->median)
			rra(stack_a);
	}
}

void	rise_value_B(s_node **stack_b, s_node *target)
{
	s_node	*tmp_ptr;

	tmp_ptr = *stack_b;
	while (*stack_b != target)
	{
		if (target->median)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void move_b(s_node **stack_a, s_node **stack_b)
{
	rise_value_A(stack_a, (*stack_b)->target);
	pa(stack_a, stack_b);
}

	void move_a(s_node **stack_a, s_node **stack_b)
{
	s_node	*cheapet_node;

	cheapet_node = find_cheapest(*stack_a);
	//verify if both cheapest and target are above or below the median line
	if (cheapet_node->median && cheapet_node->target->median) // above
		rr(stack_a, stack_b);
	else if (!cheapet_node->median && !cheapet_node->target->median) // below
		rrr(stack_a, stack_b);
	//rise the target value from A to the top stack
	rise_value_A(stack_a, cheapet_node);
	//rise the target value from B to the top stack
	rise_value_B(stack_b, cheapet_node->target);
	pb(stack_a, stack_b);
}