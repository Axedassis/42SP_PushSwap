/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:50:39 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/19 12:53:55 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_list(t_node *lst)
{
	t_node		*tmp_node;

	while (lst->next)
	{
		tmp_node = lst;
		lst = lst->next;
		free(tmp_node);
	}
	free(lst);
}

int	get_list_size(t_node *lst)
{
	int		size;
	t_node	*tmp_lst;

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

t_node	*get_last_node(t_node *stack)
{
	t_node	*tmp_node;

	tmp_node = stack;
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;
	return (tmp_node);
}

t_node	*get_node_max(t_node *stack)
{
	t_node	*max_node;
	t_node	*needle;

	needle = stack;
	max_node = needle;
	while (needle)
	{
		if (needle->data > max_node->data)
			max_node = needle;
		needle = needle->next;
	}
	return (max_node);
}

t_node	*get_node_min(t_node *stack)
{
	t_node	*min_node;
	t_node	*needle;

	needle = stack;
	min_node = needle;
	while (needle)
	{
		if (needle->data < min_node->data)
			min_node = needle;
		needle = needle->next;
	}
	return (min_node);
}
