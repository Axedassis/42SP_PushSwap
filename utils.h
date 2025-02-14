/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:50:28 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/14 14:32:39 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "libft/includes/libft.h"

typedef struct t_node
{
	long			data;
	int				index;
	int				push_cost;
	bool			median;
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
s_node	*node_max(s_node *stack);
s_node *node_min(s_node *stack);
void	update_index(s_node **stack);
s_node	*find_cheapest(s_node	*stack_n);

//LIST
void	init_stack(long	*nbrs, s_node **stack_a, int *size);
s_node	*create_node(int data, s_node *lst);
void	push_list(s_node **lst, s_node *new_node);

//VERIFY
int		list_sorted(s_node *stack_a);
void	sort_list(s_node **stack_a); //verify if is necessary to sort



//OPERATIONS
void	sa(s_node **stack_a, int print);
void	sb(s_node **stack_b, int print);
void	ss(s_node **stack_a, s_node **stack_b);
void	rra(s_node **stack_a, int print);
void	rrb(s_node **stack_b, int print);
void	rrr(s_node **stack_a, s_node **stack_b);
void	ra(s_node **stack_a, int print);
void	rb(s_node **stack_b, int print);
void	rr(s_node **stack_a, s_node **stack_b);
void	pb(s_node **stack_a, s_node **stack_b, int print);
void	pa(s_node **stack_a, s_node **stack_b, int print);

//SORT
void	sort_three(s_node **stack_a, s_node **stack_b);
void	sort_stack(s_node **stack_a, s_node **stack_b);

//SORT HELPER
void	cost_set(s_node **stack_a);
void	cost_analysis(s_node **stack_a, s_node **stack_b);
void	min_to_top(s_node **stack_n);
void	move_a(s_node **stack_a, s_node **stack_b);
void	move_b(s_node **stack_a, s_node **stack_b);
void	rise_value(s_node **stack_n, s_node *target, char stack_l);
// void	rise_value_B(s_node **stack_b, s_node *target);
// void	rise_value_A(s_node **stack_a, s_node *target);

//DEBUG
void print_list_d(s_node *stack_n);


# endif