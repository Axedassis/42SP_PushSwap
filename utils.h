/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:50:28 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/10 19:00:49 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/includes/libft.h"

typedef struct t_node
{
	int				data;
	struct t_node	*next;
	struct t_node	*previous;
} s_node;

void	free_splited(char **splited);
char	*init_str(int argc, char **argv);
int		*check_ints(char *str);
void	check_nbrs(int *nbrs);
s_node	*init_list(void);
s_node	*create_node(int data, s_node *lst);
void	push_list(s_node *lst, s_node *new_node);
void	print_list(s_node *lst);
void	free_list(s_node *lst);

# endif