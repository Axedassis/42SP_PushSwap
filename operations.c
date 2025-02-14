/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:23:27 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/14 16:34:44 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	rotate(s_node **stack);

void	sa(s_node **stack_a, int print)
{
	s_node	*next_node;
	
	if (size_list(*stack_a) <= 1 || !stack_a || !(*stack_a)->next)
		return ;
	next_node = (*stack_a)->next;
	(*stack_a)->next = next_node->next;
	next_node->next = *stack_a;
	next_node->previous = NULL;          // B's prev is NULL
	(*stack_a)->previous = next_node;   // A's prev is B
	if ((*stack_a)->next)               // If C exists:
		(*stack_a)->next->previous = *stack_a; // C's prev is A
	*stack_a = next_node;               // Update the head of the stack
	if (print)
		ft_printf("sa\n");
}

void	sb(s_node **stack_b, int print)
{
	s_node	*next_node;
	
	if (size_list(*stack_b) <= 1 || !stack_b || !(*stack_b)->next)
		return ;
	next_node = (*stack_b)->next;
	(*stack_b)->next = next_node->next;
	next_node->next = *stack_b;
	next_node->previous = NULL;          // B's prev is NULL
	(*stack_b)->previous = next_node;   // A's prev is B
	if ((*stack_b)->next)               // If C exists:
		(*stack_b)->next->previous = *stack_b; // C's prev is A
	*stack_b = next_node;               // Update the head of the stack
	if (print)
		ft_printf("sb\n");
}

void	ss(s_node **stack_a, s_node **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}

void	ra(s_node **stack_a, int print)
{
	rotate(stack_a);
	if (print)
		ft_printf("ra\n");
}

static void	rotate(s_node **stack)
{
	s_node	*last_n;

	if (!*stack || !(*stack)->next)
		return ;
	last_n = last_node(*stack);
	last_n->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last_n->next->previous = last_n;
	last_n->next->next = NULL;
}

void	pa(s_node **stack_a, s_node **stack_b, int print)
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
	top_node->previous = NULL; // Reset previous to NULL
	if (print)
		ft_printf("pa\n");
}

void	pb(s_node **stack_a, s_node **stack_b, int print)
{
	s_node	*top_node;

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
	top_node->previous = NULL; // Reset previous to NULL
	if (print)
		ft_printf("pb\n");
}

void	rb(s_node **stack_b, int print)
{
	rotate(stack_b);
	if (print)
		ft_printf("ra\n");
}


void	rr(s_node **stack_a, s_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);

	ft_printf("rr\n");
}

void	rrr(s_node **stack_a, s_node **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_printf("rrr\n");
}

static void	rev_rotate(s_node **stack) 
{
	s_node	*last; 

	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last->previous->next = NULL;
	last->next = *stack;
	last->previous = NULL;
	*stack = last;
	last->next->previous = last;
}



void	rra(s_node **stack_a, int print)
{
	rev_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(s_node **stack_b, int print)
{
	rev_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

