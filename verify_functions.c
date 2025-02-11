/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:02:38 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/11 18:20:47 by lsilva-x         ###   ########.fr       */
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
		else if (size_list(*stack_a) > 2)
		{
			sort_three(stack_a, &stack_b);
			print_list(*stack_a);
			ft_printf("\n");
			print_list(stack_b);
		}
		else
		{
			//NORMAL SORT
		}
	}
}

static void	sort_three(s_node **stack_a, s_node **stack_b)
{
	pb(stack_a, stack_b);
}
