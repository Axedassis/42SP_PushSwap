/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:46:59 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/13 13:04:45 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	reroll_data_a(s_node **stack_a, s_node **stack_b);
static void	reroll_data_b(s_node **stack_a, s_node **stack_b);
static void	update_target(s_node **stack_a, s_node **stack_b);
static void	cost_set(s_node **stack_a);
static void	cost_analysis(s_node **stack_a, s_node **stack_b);
static void	update_target(s_node **stack_a, s_node **stack_b);

void	sort_stack(s_node **stack_a, s_node **stack_b)
{
	int		size_a;

	size_a = size_list(stack_a);
	if (size_a-- > 3 && !list_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (size_a-- > 3 && !list_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (size_a > 3 && !list_sorted(*stack_a))
	{
		reroll_data_a(stack_a, stack_b);
		move_a(stack_a, stack_b);
	}
	sort_three(stack_a, stack_b);
	while (*stack_b)
	{

	}
	update_index(stack_a);
}

static void	reroll_data_b(s_node **stack_a, s_node **stack_b)
{
	update_index(stack_a);
	update_index(stack_b);
	
}

static void	rise_value_A(s_node **stack_a, s_node *target)
{
	s_node	*tmp_ptr;

	tmp_ptr = *stack_a;
	while (stack_a != target)
	{
		if (target->median)
			ra(stack_a);
		if (!target->median)
			rra(stack_a);
	}
}

static void	rise_value_B(s_node **stack_b, s_node *target)
{
	s_node	*tmp_ptr;

	tmp_ptr = *stack_b;
	while (stack_b != target)
	{
		if (target->median)
			rb(stack_b);
		if (!target->median)
			rrb(stack_b);
	}
}

static void move_a(s_node **stack_a, s_node **stack_b)
{
	s_node	*cheapet_node;

	cheapet_node = find_cheapest(stack_a);
	//verify if both cheapest and target are above or below the median line
	if (cheapet_node->median && cheapet_node->target->median) // above
		rr(stack_a, stack_b);
	else if (!cheapet_node->median && !cheapet_node->target->median) // below
		rrr(stack_a, stack_b);
	//rise the target value from A to the top stack
	rise_value_A(stack_a, cheapet_node);
	//rise the target value from B to the top stack
	rise_value_B(stack_b, cheapet_node);
	pb(stack_a, stack_b);
}

static void	cost_set(s_node **stack_a)
{
	s_node	*tmp_node;
	s_node	*cheap_node;
	long	cheapest;

	tmp_node = *stack_a;
	cheapest = LONG_MAX;
	while (tmp_node)
	{
		if (tmp_node->cheapest < cheap_node)
		{
			cheap_node = tmp_node;
			cheapest = tmp_node->cheapest;
		}
		tmp_node = tmp_node->next;
	}
}

static void	reroll_data(s_node **stack_a, s_node **stack_b)
{
	//update all the index and set if it above or below the median line
	update_index(stack_a); 
	update_index(stack_b);
	//set the target based on the turkish algorithm
	update_target(stack_a, stack_b);
	//make the cost analysis based in the median line and the index of each node
	cost_analysis(stack_a, stack_b);
	//bubble search throughout the cheapest cost value;
	cost_set(stack_a);
}

static void	cost_analysis(s_node **stack_a, s_node **stack_b)
{
	s_node	*tmp_stack;
	int		a_size;
	int		b_size;

	tmp_stack = *stack_a;
	a_size = size_list(stack_a);
	b_size = size_list(stack_b);

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

static void	update_target(s_node **stack_a, s_node **stack_b)
{
	s_node	*a_tmp;
	s_node	*b_tmp;
	int		smallest_diff;

	smallest_diff = INT_MIN;
	a_tmp = *stack_a;
	b_tmp = *stack_b;
	while (a_tmp) 
	{
		b_tmp = *stack_b;
		while(b_tmp)
		{
			/*
			This function iterates through each node in stack 'A' and compares
			the current node with each element of stack 'B' to check if the 'B'
			value is smaller than the current 'A' element

			In this iteration, we find the smallest value in the stack and set it
			as the target and the value. If there is no smaller value, we set the
			largest value of stack 'B' as the target for the current element of stack 'A'

			best_match_index -> Since A is always greater than B, we are checking
			if the current value of A is sufficiently larger to be closer to B. Therefore,
			the difference between A and B is smaller, making the best_match the
			value with the smallest possible difference
			 */
			if (b_tmp->data < a_tmp->data && b_tmp->data > smallest_diff)
			{ 
				smallest_diff = b_tmp->data;
				a_tmp->target = b_tmp;
			}
			b_tmp = b_tmp->next;
		}
		if (smallest_diff == LONG_MIN)
			a_tmp->target = node_max(stack_b);
		a_tmp = a_tmp->next;
	}
}