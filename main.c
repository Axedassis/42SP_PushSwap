/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:59:32 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/11 11:21:59 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	teste(int	*nbrs);

int	main(int argc, char **argv)
{
	char	*str;
	int		*nbrs;

	if (argc == 1)
		return (-1);
	str = init_str(argc, argv);
	if (!str)
		return (-1);
	nbrs = check_ints(str);
	check_nbrs(nbrs);
	teste(nbrs);
	return (0);
}


static void	teste(int	*nbrs)
{
	s_node	*stack_a;
	s_node	*new_node;
	int		i;

	i = 0;
	stack_a = NULL;
	while (nbrs[i])
	{
		new_node = create_node(nbrs[i], stack_a);
		push_list(&stack_a, new_node);
		i++;
	}
	print_list(stack_a);
	free_list(stack_a);
	free (nbrs);
}