/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:23:27 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/19 12:41:34 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sb(t_node **stack_b, int print);
void	pb(t_node **stack_a, t_node **stack_b, int print);
void	rb(t_node **stack_b, int print);
void	rrb(t_node **stack_b, int print);
void	rise_value_b(t_node **stack_b, t_node *target);

void	sb(t_node **stack_b, int print)
{
	t_node	*next_node;

	if (get_list_size(*stack_b) <= 1 || !stack_b || !(*stack_b)->next)
		return ;
	next_node = (*stack_b)->next;
	(*stack_b)->next = next_node->next;
	next_node->next = *stack_b;
	next_node->previous = NULL;
	(*stack_b)->previous = next_node;
	if ((*stack_b)->next)
		(*stack_b)->next->previous = *stack_b;
	*stack_b = next_node;
	if (print)
		ft_printf("sb\n");
}

void	pb(t_node **stack_a, t_node **stack_b, int print)
{
	t_node	*top_node;

	if (!(*stack_a))
		return ;
	top_node = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	top_node->next = *stack_b;
	if (*stack_b)
		(*stack_b)->previous = top_node;
	*stack_b = top_node;
	top_node->previous = NULL;
	if (print)
		ft_printf("pb\n");
}

void	rb(t_node **stack_b, int print)
{
	t_node	*last_n;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last_n = get_last_node(*stack_b);
	last_n->next = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->previous = NULL;
	last_n->next->previous = last_n;
	last_n->next->next = NULL;
	if (print)
		ft_printf("rb\n");
}

void	rrb(t_node **stack_b, int print)
{
	t_node	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = get_last_node(*stack_b);
	last->previous->next = NULL;
	last->next = *stack_b;
	last->previous = NULL;
	*stack_b = last;
	last->next->previous = last;
	if (print)
		ft_printf("rrb\n");
}

void	rise_value_b(t_node **stack_b, t_node *target)
{
	while (*stack_b != target)
	{
		if (target->median)
			rb(stack_b, 1);
		else
			rrb(stack_b, 1);
	}
}
