/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:49:19 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/13 15:57:23 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void print_list_d(s_node *stack_n)
{
	struct t_node *current = stack_n;
	while (current != NULL) {
		printf("Node at index %d:\n", current->index);
		printf("  data: %ld\n", current->data);
		printf("  push_cost: %d\n", current->push_cost);
		printf("  median: %s\n", current->median ? "true" : "false");
		printf("  cheapest: %s\n", current->cheapest ? "true" : "false");
		printf("  target: %p\n", (void *)current->target);
		printf("  previous: %p\n", (void *)current->previous);
		printf("  next: %p\n", (void *)current->next);
		current = current->next;
	}
}