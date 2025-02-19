/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:59:32 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/19 12:44:21 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char **argv)
{
	char	*str;
	int		size;
	t_node	*stack_a;
	long	*nbrs;

	size = 0;
	stack_a = NULL;
	if (argc == 1)
		return (-1);
	str = init_str(argc, argv);
	if (!str)
		return (-1);
	nbrs = check_input(str, &size);
	validate_values(nbrs, &size);
	init_stack(nbrs, &stack_a, &size);
	sort_list(&stack_a);
	free_list(stack_a);
	return (0);
}

void	sort_list(t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (!is_stack_sorted(*stack_a))
	{
		if (get_list_size(*stack_a) == 2)
			sa(stack_a, 1);
		else if (get_list_size(*stack_a) == 3)
			three_sort(stack_a);
		else
			stack_sort(stack_a, &stack_b);
	}
}

void	three_sort(t_node **stack_a)
{
	t_node	*biggest;

	biggest = get_node_max(*stack_a);
	if (biggest == *stack_a)
		ra(stack_a, 1);
	else if ((*stack_a)->next == biggest)
		rra(stack_a, 1);
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, 1);
}
