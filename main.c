/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:59:32 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/20 14:19:11 by lsilva-x         ###   ########.fr       */
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
	if (ft_strcmp(argv[1], "") == 0)
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
