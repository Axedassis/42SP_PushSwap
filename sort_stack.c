/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:46:59 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/13 20:17:29 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	reroll_data_a(s_node **stack_a, s_node **stack_b);
static void	reroll_data_b(s_node **stack_a, s_node **stack_b);
static void	update_target_a(s_node **stack_a, s_node **stack_b);
static void	update_target_b(s_node **stack_a, s_node **stack_b);

void	sort_stack(s_node **stack_a, s_node **stack_b)
{
	int		size_a;

	size_a = size_list(*stack_a);
	printf("size_list A: %d\n", size_a);
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
		reroll_data_b(stack_a, stack_b);
		move_b(stack_a, stack_b);
	}
	update_index(stack_a);
	min_to_top(stack_a);
}

static void	reroll_data_b(s_node **stack_a, s_node **stack_b)
{
	update_index(stack_a);
	update_index(stack_b);
	printf("\n\n\n");
	print_list_d(*stack_b);
	update_target_b(stack_a, stack_b);
}

static void	reroll_data_a(s_node **stack_a, s_node **stack_b)
{
	//update all the index and set if it above or below the median line
	update_index(stack_a); 
	update_index(stack_b);
	//set the target based on the turkish algorithm
	update_target_a(stack_a, stack_b);
	//make the cost analysis based in the median line and the index of each node
	cost_analysis(stack_a, stack_b);
	//bubble search throughout the cheapest cost value;
	cost_set(stack_a);
}

static void	update_target_b(s_node **stack_a, s_node **stack_b)
{
	s_node	*a_tmp;
	s_node	*b_tmp;
	long	bigger_diff;

	b_tmp = *stack_b;
	a_tmp = *stack_a;
	while (b_tmp)
	{
	bigger_diff = LONG_MAX;
	a_tmp = stack_a;
		
		if (a_tmp->data > b_tmp->data && a_tmp->data < bigger_diff)
		{ 
			bigger_diff = a_tmp->data;
			b_tmp->target = a_tmp;
		}
		a_tmp = a_tmp->next;
	}
	if (bigger_diff == LONG_MIN)
		b_tmp->target = node_min(*stack_a);
	b_tmp = b_tmp->next;
}

static void	update_target_a(s_node **stack_a, s_node **stack_b)
{
	s_node	*a_tmp;
	s_node	*b_tmp;
	long	smallest_diff;

	smallest_diff = LONG_MIN;
	a_tmp = *stack_a;
	b_tmp = *stack_b;
	while (a_tmp) 
	{
		smallest_diff = LONG_MIN;
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
			a_tmp->target = node_max(*stack_b);
		a_tmp = a_tmp->next;
	}
}