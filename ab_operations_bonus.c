/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:21:04 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/19 18:45:00 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	ss(t_node **stack_a, t_node **stack_b, int cod)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (cod)
		ft_printf("ss\n");
}

void	rr(t_node **stack_a, t_node **stack_b, int cod)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (cod)
		ft_printf("rr\n");
}

void	rrr(t_node **stack_a, t_node **stack_b, int cod)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (cod)
		ft_printf("rrr\n");
}
