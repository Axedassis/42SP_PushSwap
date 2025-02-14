/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:46:59 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/14 14:44:21 by lsilva-x         ###   ########.fr       */
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
	if (size_a-- > 3 && !list_sorted(*stack_a))
		pb(stack_a, stack_b, 1);
	if (size_a-- > 3 && !list_sorted(*stack_a))
		pb(stack_a, stack_b, 1);
	while (size_a-- > 3 && !list_sorted(*stack_a))
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
	update_target_b(stack_a, stack_b);
}

static void	reroll_data_a(s_node **stack_a, s_node **stack_b)
{
	update_index(stack_a); 
	update_index(stack_b);
	update_target_a(stack_a, stack_b);
	cost_analysis(stack_a, stack_b);
	cost_set(stack_a);
}

static void	update_target_b(s_node **stack_a, s_node **stack_b)
{
	s_node	*a_tmp;
	s_node	*b_tmp;
	s_node	*target_node;
	long	bigger_diff;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b) // Guard against empty stacks
		return ;

	b_tmp = *stack_b;
	while (b_tmp)
	{
		bigger_diff = LONG_MAX;
		target_node = NULL; // Initialize to NULL
		a_tmp = *stack_a;
		while (a_tmp)
		{
			if (a_tmp->data > b_tmp->data && a_tmp->data < bigger_diff)
			{ 
				bigger_diff = a_tmp->data;
				target_node = a_tmp;
			}
			a_tmp = a_tmp->next;
		}
		if (bigger_diff == LONG_MAX)
			b_tmp->target = node_min(*stack_a);
		else
			b_tmp->target = target_node; // Now safe (target_node initialized)
		b_tmp = b_tmp->next;
	}
}

static void	update_target_a(s_node **stack_a, s_node **stack_b)
{
	s_node	*a_tmp;
	s_node	*b_tmp;
	s_node *target_node;
	long	smallest_diff;

	target_node = NULL;
	if (!stack_b || !*stack_b)
		return ;
	smallest_diff = LONG_MIN;
	a_tmp = *stack_a;
	b_tmp = *stack_b;
	while (a_tmp) 
	{
		smallest_diff = LONG_MIN;
		b_tmp = *stack_b;
		while(b_tmp)
		{
			if (b_tmp->data < a_tmp->data && b_tmp->data > smallest_diff)
			{ 
				smallest_diff = b_tmp->data;
				target_node = b_tmp;
			}
			b_tmp = b_tmp->next;
		}
		if (smallest_diff == LONG_MIN)
			a_tmp->target = node_max(*stack_b);
		else
			a_tmp->target = target_node;
		a_tmp = a_tmp->next;
	}
}