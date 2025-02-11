/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:50:39 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/11 16:14:44 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_list(s_node *lst)
{
	s_node		*tmp_lst;

	tmp_lst = lst;
	while (tmp_lst)
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
	size = 0;
	while (tmp_lst)
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