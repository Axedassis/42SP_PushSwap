/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:02:38 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/11 12:09:11 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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