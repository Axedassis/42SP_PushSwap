/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:23:27 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/11 15:21:43 by lsilva-x         ###   ########.fr       */
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

void	sa(s_node **stack_b)
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