/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:23:27 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/13 16:52:59 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sa(s_node **stack_a)
{
	s_node	*next_node;
	
	if (size_list(*stack_a) <= 1 || !stack_a || !(*stack_a)->next)
		return ;
	next_node = (*stack_a)->next;
	(*stack_a)->next = next_node->next;
	next_node->next = *stack_a;
	*stack_a = next_node;
}

void	sb(s_node **stack_b)
{
	s_node	*next_node;
	
	if (size_list(*stack_b) <= 1 || !stack_b || !(*stack_b)->next)
		return ;
	next_node = (*stack_b)->next;
	(*stack_b)->next = next_node->next;
	next_node->next = *stack_b;
	*stack_b = next_node;
}

void	ss(s_node **stack_a, s_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	ra(s_node **stack_a)
{
	s_node	*last_n;
	s_node	*next_new_node;
	
	if (!stack_a || size_list(*stack_a) <= 1 || !(*stack_a)->next)
		return ;
	next_new_node = (*stack_a)->next;
	last_n = last_node(*stack_a);
	last_n->next = *stack_a;
	(*stack_a)->next = NULL;
	(*stack_a)->previous = last_n;
	*stack_a = next_new_node;
	(*stack_a)->previous = NULL;
}

void	pa(s_node **stack_a, s_node **stack_b)
{
	s_node	*top_node;

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
}

void	pb(s_node **stack_a, s_node **stack_b)
{
	s_node	*top_node;

	if (!stack_a || !(*stack_a))
		return ;
	top_node = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	top_node->next = *stack_b;
	top_node->previous = NULL;
	if (*stack_b != NULL)
		(*stack_b)->previous = top_node;
	*stack_b = top_node;
}

void	rb(s_node **stack_b)
{
	s_node	*last_n;
	s_node	*next_new_node;
	
	if (!stack_b || size_list(*stack_b) <= 1 || !(*stack_b)->next)
		return ;
	next_new_node = (*stack_b)->next;
	last_n = last_node(*stack_b);
	last_n->next = *stack_b;
	(*stack_b)->next = NULL;
	(*stack_b)->previous = last_n;
	*stack_b = next_new_node;
	(*stack_b)->previous = NULL;
	last_n->previous = NULL;
}

void	rr(s_node **stack_a, s_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(s_node **stack_a)
{
	s_node	*last_n;
	s_node	*previous_node;
	
	if (!stack_a || size_list(*stack_a) <= 1 || !(*stack_a)->next)
		return ;

	last_n = last_node(*stack_a);
	previous_node = last_n->previous;
	previous_node->next = NULL;
	last_n->previous = NULL;
	last_n->next = *stack_a;
	*stack_a = last_n;
	(*stack_a)->next->previous = *stack_a;
}

void	rrb(s_node **stack_b)
{
	s_node	*last_n;
	s_node	*previous_node;
	
	if (!stack_b || size_list(*stack_b) <= 1 || !(*stack_b)->next)
		return ;

	last_n = last_node(*stack_b);
	previous_node = last_n->previous;
	previous_node->next = NULL;
	last_n->previous = NULL;
	last_n->next = *stack_b;
	*stack_b = last_n;
}

void	rrr(s_node **stack_a, s_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
