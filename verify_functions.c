/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:02:38 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/11 19:56:43 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	sort_three(s_node **stack_a, s_node **stack_b);

int		list_sorted(s_node *stack_a)
{
	s_node	*x;
	s_node	*y;

	x = stack_a;
	while(x)
	{
		y = x;
		while (y)
		{
			if (x->data > y->data)
				return (0);
			y = y->next;
		}
		x = x->next;
	}
	return (1);
}

void	sort_list(s_node **stack_a)
{
	s_node	*stack_b;

	stack_b = NULL;
	if (!list_sorted(*stack_a))
	{
		if (size_list(*stack_a) == 2)
			sa(stack_a);
		else if (size_list(*stack_a) == 3)
			sort_three(stack_a, &stack_b);
		else
		{
			//NORMAL SORT
		}
	}
}

static void	sort_three(s_node **stack_a, s_node **stack_b)
{
	s_node	*biggest;
	
	(void)stack_b;
	biggest = node_max(*stack_a);
	if (biggest == *stack_a) // 3 2 1 || 3 1 2 -> 2 1 3 || 1 2 3
		ra(stack_a);
	else if ((*stack_a)->next == biggest) //1 3 2 || 2 3 1 ->  2 1 3 || 1 2 3
		rra(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data) // 2 1 3 -> 1 2 3
		sa(stack_a);
}
