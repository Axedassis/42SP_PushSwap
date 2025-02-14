/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:59:32 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/14 16:29:38 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char **argv)
{
	char	*str;
	int		size;
	s_node	*stack_a;
	long	*nbrs;

	size = 0;
	stack_a = NULL;
	if (argc == 1)
		return (-1);
	str = init_str(argc, argv);
	if (!str)
		return (-1);
	nbrs = check_ints(str, &size);
	check_nbrs(nbrs, &size);
	init_stack(nbrs, &stack_a, &size);
	sort_list(&stack_a);
	free_list(stack_a);
	return (0);
}
