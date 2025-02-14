/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:02:38 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/14 11:33:54 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sort_list(s_node **stack_a)
{
	s_node	*stack_b;

	stack_b = NULL;
	if (!list_sorted(*stack_a))
	{
		if (size_list(*stack_a) == 2)
			sa(stack_a, 1);
		else if (size_list(*stack_a) == 3)
			sort_three(stack_a, &stack_b);
		else
			sort_stack(stack_a, &stack_b);
	}
}

void	sort_three(s_node **stack_a, s_node **stack_b)
{
	s_node	*biggest;
	
	(void)stack_b;
	biggest = node_max(*stack_a);
	if (biggest == *stack_a) // 3 2 1 || 3 1 2 -> 2 1 3 || 1 2 3
		ra(stack_a, 1);
	else if ((*stack_a)->next == biggest) //1 3 2 || 2 3 1 ->  2 1 3 || 1 2 3
		rra(stack_a, 1);
	if ((*stack_a)->data > (*stack_a)->next->data) // 2 1 3 -> 1 2 3
		sa(stack_a, 1);
}
