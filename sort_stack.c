/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:46:59 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/19 12:52:48 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	uptade_stack_a(t_node **stack_a, t_node **stack_b);
static void	update_target_a(t_node **stack_a, t_node **stack_b);
static void	uptade_stack_b(t_node **stack_a, t_node **stack_b);
static void	update_target_b(t_node **stack_a, t_node **stack_b);

void	stack_sort(t_node **stack_a, t_node **stack_b)
{
	int		size_a;

	size_a = get_list_size(*stack_a);
	if (size_a-- > 3 && !is_stack_sorted(*stack_a))
		pb(stack_a, stack_b, 1);
	if (size_a-- > 3 && !is_stack_sorted(*stack_a))
		pb(stack_a, stack_b, 1);
	while (size_a-- > 3 && !is_stack_sorted(*stack_a))
	{
		uptade_stack_a(stack_a, stack_b);
		move_a(stack_a, stack_b);
	}
	three_sort(stack_a);
	while (*stack_b)
	{
		uptade_stack_b(stack_a, stack_b);
		move_b(stack_a, stack_b);
	}
	update_stack_index(stack_a);
	min_to_top(stack_a);
}

static void	uptade_stack_b(t_node **stack_a, t_node **stack_b)
{
	update_stack_index(stack_a);
	update_stack_index(stack_b);
	update_target_b(stack_a, stack_b);
}

static void	uptade_stack_a(t_node **stack_a, t_node **stack_b)
{
	update_stack_index(stack_a);
	update_stack_index(stack_b);
	update_target_a(stack_a, stack_b);
	analyze_cost(stack_a, stack_b);
	set_cost(stack_a);
}

static void	update_target_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*a_tmp;
	t_node	*b_tmp;
	t_node	*target_node;
	long	bigger_diff;

	b_tmp = *stack_b;
	while (b_tmp)
	{
		bigger_diff = LONG_MAX;
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
			b_tmp->target = get_node_min(*stack_a);
		else
			b_tmp->target = target_node;
		b_tmp = b_tmp->next;
	}
}

static void	update_target_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*a_tmp;
	t_node	*b_tmp;
	t_node	*target_node;
	long	smallest_diff;

	a_tmp = *stack_a;
	while (a_tmp)
	{
		smallest_diff = LONG_MIN;
		b_tmp = *stack_b;
		while (b_tmp)
		{
			if (b_tmp->data < a_tmp->data && b_tmp->data > smallest_diff)
			{
				smallest_diff = b_tmp->data;
				target_node = b_tmp;
			}
			b_tmp = b_tmp->next;
		}
		if (smallest_diff == LONG_MIN)
			a_tmp->target = get_node_max(*stack_b);
		else
			a_tmp->target = target_node;
		a_tmp = a_tmp->next;
	}
}
