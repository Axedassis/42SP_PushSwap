/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:50:28 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/12 16:29:08 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/includes/libft.h"

typedef struct t_node
{
	long			data;
	int				index;
	int				push_cost;
	bool			cheapest;
	struct t_node	*next;
	struct t_node	*target;
	struct t_node	*previous;
} s_node;

char	*init_str(int argc, char **argv);

//HANDLER | CHECKER
long	*check_ints(char *str, int *size);
void	check_nbrs(long *nbrs, int *size);

//FREE
void	free_splited(char **splited);
void	free_list(s_node *lst);

//UTILS
int		size_list(s_node *lst);
void	print_list(s_node *lst);
s_node	*last_node(s_node *stack);
s_node *node_max(s_node *stack);

//LIST
void	init_stack(long	*nbrs, s_node **stack_a, int *size);
s_node	*create_node(int data, s_node *lst);
void	push_list(s_node **lst, s_node *new_node);

//VERIFY
int		list_sorted(s_node *stack_a);
void	sort_list(s_node **stack_a); //verify if is necessary to sort

//OPERATIONS
void	sa(s_node **stack_a);
void	sb(s_node **stack_b);
void	ss(s_node **stack_a, s_node **stack_b);
void	rra(s_node **stack_a);
void	rrb(s_node **stack_b);
void	rrr(s_node **stack_a, s_node **stack_b);
void	ra(s_node **stack_a);
void	rb(s_node **stack_b);
void	rrr(s_node **stack_a, s_node **stack_b);
void	pb(s_node **stack_a, s_node **stack_b);


# endif