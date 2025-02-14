/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:26:16 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/14 16:46:26 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_splited(char **splited);
void	check_nbrs(long *nbrs, int *size);
void	update_index(s_node **stack);
s_node	*find_cheapest(s_node	*stack_n);
int		list_sorted(s_node *stack_a);

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

void	check_nbrs(long *nbrs, int *size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < *size)
	{
		j = i + 1;
		while (j < *size)
		{
			if (nbrs[j] == nbrs[i] || nbrs[j] > 2147483647 || nbrs[j] < -2147483647)
			{
				i = 0;
				ft_printf("Error\n");
				exit(-1);
			}
			j++;
		}
		i++;
	}
}

void update_index(s_node **stack)
{
	int		i;
	int		median_val;
	s_node	*tmp_stack;

	if (!*stack)
		return ;
	median_val = size_list(*stack) / 2;
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

s_node	*find_cheapest(s_node	*stack_n)
{
	s_node	*cheapest;

	cheapest = NULL;
	while (stack_n)
	{
		if (stack_n->cheapest)
			cheapest = stack_n;
		stack_n = stack_n->next;
	}
	return (cheapest);
}

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
