/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:20:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/19 12:31:46 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sa(t_node **stack_a, int print);
void	ra(t_node **stack_a, int print);
void	pa(t_node **stack_a, t_node **stack_b, int print);
void	rra(t_node **stack_a, int print);
void	rise_value_a(t_node **stack_a, t_node *target);

void	sa(t_node **stack_a, int print)
{
	t_node	*next_node;

	if (get_list_size(*stack_a) <= 1 || !stack_a || !(*stack_a)->next)
		return ;
	next_node = (*stack_a)->next;
	(*stack_a)->next = next_node->next;
	next_node->next = *stack_a;
	next_node->previous = NULL;
	(*stack_a)->previous = next_node;
	if ((*stack_a)->next)
		(*stack_a)->next->previous = *stack_a;
	*stack_a = next_node;
	if (print)
		ft_printf("sa\n");
}

void	ra(t_node **stack_a, int print)
{
	t_node	*last_n;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last_n = get_last_node(*stack_a);
	last_n->next = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->previous = NULL;
	last_n->next->previous = last_n;
	last_n->next->next = NULL;
	if (print)
		ft_printf("ra\n");
}

void	pa(t_node **stack_a, t_node **stack_b, int print)
{
	t_node	*top_node;

	if (!stack_a || !stack_b || !(*stack_b))
		return ;
	top_node = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->previous = NULL;
	top_node->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->previous = top_node;
	*stack_a = top_node;
	top_node->previous = NULL;
	if (print)
		ft_printf("pa\n");
}

void	rra(t_node **stack_a, int print)
{
	t_node	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = get_last_node(*stack_a);
	last->previous->next = NULL;
	last->next = *stack_a;
	last->previous = NULL;
	*stack_a = last;
	last->next->previous = last;
	if (print)
		ft_printf("rra\n");
}

void	rise_value_a(t_node **stack_a, t_node *target)
{
	while (*stack_a != target)
	{
		if (target->median)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}
