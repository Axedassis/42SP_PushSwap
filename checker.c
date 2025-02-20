/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:11:25 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/19 20:55:06 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	applay_move_a(char *str, t_node **stack_a, t_node **stack_b);
static void	applay_move_b(char *str, t_node **stack_a, t_node **stack_b);
static void	node_process(char *str, t_node **stack_a, t_node **stack_b);

static void	process_input(t_node **stack_a, t_node **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(STDIN_FILENO, 0);
		if (!str)
		{
			if (is_stack_sorted(*stack_a) == 1 && get_list_size(*stack_b) == 0)
			{
				exit_safe("OK\n", str);
				free_list(*stack_a);
				exit (0);
			}
			free_lists(*stack_a, *stack_b);
			break ;
		}
		if (ft_strlen(str) > 0)
			node_process(str, stack_a, stack_b);
		free(str);
	}
}

static void	node_process(char *str, t_node **stack_a, t_node **stack_b)
{
	str[ft_strlen(str) - 1] = '\0';
	if (checker_verify(str) || ft_strcmp(str, "") == 0)
	{
		if (is_stack_sorted(*stack_a) == 1 && get_list_size(*stack_b) == 0)
		{
			exit_safe("OK\n", str);
			free_list(*stack_a);
			exit (0);
		}
		applay_move_a(str, stack_a, stack_b);
	}
	else
	{
		exit_safe("Error\n", str);
		free_lists(*stack_a, *stack_b);
		exit (0);
	}
}

static void	applay_move_a(char *str, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(str, "pa") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pb") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "ra") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(str, "rb") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(str, "sa") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(str, "sb") == 0)
		sb(stack_a, 0);
	else if (ft_strcmp(str, "ss") == 0)
		ss(stack_a, stack_b, 1);
	applay_move_b(str, stack_a, stack_b);
}

static void	applay_move_b(char *str, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(str, "rr") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "rrb") == 0)
		rrb(stack_a, 0);
	else if (ft_strcmp(str, "rra") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(stack_a, stack_b, 0);
}

int	main(int argc, char **argv)
{
	char	*str;
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;
	long	*nbrs;

	size = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (-1);
	str = init_str(argc, argv);
	if (!str)
		return (-1);
	nbrs = check_input(str, &size);
	validate_values(nbrs, &size);
	init_stack(nbrs, &stack_a, &size);
	process_input(&stack_a, &stack_b);
	printf("KO\n");
	return (0);
}
