/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:26:16 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/23 13:56:42 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_splited(char **splited);
void	validate_values(long *nbrs, int *size);
void	update_stack_index(t_node **stack);
t_node	*get_cheapest(t_node	*stack_n);
int		is_stack_sorted(t_node *stack_a);

void	free_splited(char **splited)
{
	int		i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	validate_values(long *nbrs, int *size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= *size)
	{
		j = i + 1;
		while (j <= *size)
		{
			if (nbrs[j] == nbrs[i] || nbrs[i] > INT_MAX || nbrs[i] < INT_MIN)
			{
				i = 0;
				free(nbrs);
				ft_printf("Error\n");
				exit(-1);
			}
			j++;
		}
		i++;
	}
}

void	update_stack_index(t_node **stack)
{
	int		i;
	int		median_val;
	t_node	*tmp_stack;

	if (!*stack)
		return ;
	median_val = get_list_size(*stack) / 2;
	tmp_stack = *stack;
	i = 0;
	while (tmp_stack)
	{
		tmp_stack->index = i;
		if (i <= median_val)
			tmp_stack->median = true;
		else
			tmp_stack->median = false;
		tmp_stack = tmp_stack->next;
		i++;
	}
}

t_node	*get_cheapest(t_node	*stack_n)
{
	while (stack_n)
	{
		if (stack_n->cheapest)
			return (stack_n);
		stack_n = stack_n->next;
	}
	return (NULL);
}

int	is_stack_sorted(t_node *stack_a)
{
	t_node	*x;
	t_node	*y;

	x = stack_a;
	while (x)
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
