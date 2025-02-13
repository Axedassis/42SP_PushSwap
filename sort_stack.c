/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:46:59 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/12 20:51:12 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	reroll_data(s_node **stack_a, s_node **stack_b);
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
		reroll_data(stack_a, stack_b);
	}
}

static void	reroll_data(s_node **stack_a, s_node **stack_b)
{
	update_index(stack_a);
	update_index(stack_b);
	update_target(stack_a, stack_b);
	cost_analysis();
}

static void	cost_analysis()
{
	
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