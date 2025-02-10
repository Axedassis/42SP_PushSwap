/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:41:42 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/10 19:04:25 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

s_node	*init_list(void)
{
	s_node		*lst;

	lst = (s_node *)malloc(sizeof(s_node) * 1);
	if (!lst)
	{
		ft_printf("Error\n");
		exit(1);
	}
	lst->data = 0;
	lst->next = NULL;
	lst->previous = NULL;
	return (lst);
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
}

s_node	*create_node(int data, s_node *lst)
{
	s_node	*new_node;

	new_node = (s_node *)malloc(sizeof(s_node) * 1);
	if (!new_node)
	{
		free_list(lst);
		exit(-1);
	}
	new_node->data = data;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void	push_list(s_node *lst, s_node *new_node)
{
	s_node	*tmp_node;

	if (lst->data == 0 && !lst->next && lst->previous)
		lst = new_node;
	else
	{
		tmp_node = lst;
		while (tmp_node->next != NULL)
			tmp_node = tmp_node->next;
		tmp_node->next = new_node;
	}
}

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