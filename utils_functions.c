/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:50:39 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/13 17:08:10 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_list(s_node *lst)
{
	s_node		*tmp_lst;

	tmp_lst = lst;
	while (tmp_lst != NULL)
	{
		ft_printf("Data: %d\n", tmp_lst->data);
		tmp_lst = tmp_lst->next;
	}
}

void	free_list(s_node *lst)
{
	s_node		*tmp_node;

	while(lst->next)
	{
		tmp_node = lst;
		lst = lst->next;
		free(tmp_node);
	}
	free(lst);
}

int	size_list(s_node *lst)
{
	int		size;
	s_node	*tmp_lst;

	tmp_lst = lst;
	if (tmp_lst == NULL)
		return (0);
	size = 0;
	while (tmp_lst != NULL)
	{
		tmp_lst = tmp_lst->next;
		size++;
	}
	return (size);
}

s_node	*last_node(s_node *stack)
{
	s_node	*tmp_node;

	tmp_node = stack;
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;
	return (tmp_node);
}

s_node *node_max(s_node *stack)
{
	s_node	*max_node;
	s_node	*needle;

	needle = stack;
	max_node = needle;
	while(needle)
	{
		if (needle->data > max_node->data)
			max_node = needle;
		needle = needle->next;
	}
	return (max_node);
}

s_node *node_min(s_node *stack)
{
	s_node	*min_node;
	s_node	*needle;

	needle = stack;
	min_node = needle;
	while(needle)
	{
		if (needle->data < min_node->data)
			min_node = needle;
		needle = needle->next;
	}
	return (min_node);
}