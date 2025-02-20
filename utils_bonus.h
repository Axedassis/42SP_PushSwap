/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:50:28 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/20 15:04:18 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/includes/libft.h"

typedef struct s_node
{
	long			data;
	int				index;
	int				push_cost;
	bool			median;
	bool			cheapest;
	struct s_node	*next;
	struct s_node	*target;
	struct s_node	*previous;
}	t_node;

char	*init_str(int argc, char **argv);

//HANDLER | CHECKER
long	*check_input(char *str, int *size);
void	validate_values(long *nbrs, int *size);

//FREE
void	free_splited(char **splited);
void	free_list(t_node *lst);
void	free_lists(t_node *stack_a, t_node *stack_b);

//UTILS
int		get_list_size(t_node *lst);
t_node	*get_last_node(t_node *stack);
t_node	*get_node_max(t_node *stack);
t_node	*get_node_min(t_node *stack);
t_node	*get_cheapest(t_node	*stack_n);
void	update_stack_index(t_node **stack);

//LIST
void	init_stack(long	*nbrs, t_node **stack_a, int *size);
t_node	*create_node(int data, t_node *lst);
void	push_list(t_node **lst, t_node *new_node);

//VERIFY
int		is_stack_sorted(t_node *stack_a);
void	sort_list(t_node **stack_a);

//OPERATIONS
void	sa(t_node **stack_a, int print);
void	sb(t_node **stack_b, int print);
void	ss(t_node **stack_a, t_node **stack_b, int cod);
void	rra(t_node **stack_a, int print);
void	rrb(t_node **stack_b, int print);
void	rrr(t_node **stack_a, t_node **stack_b, int cod);
void	ra(t_node **stack_a, int print);
void	rb(t_node **stack_b, int print);
void	rr(t_node **stack_a, t_node **stack_b, int cod);
void	pb(t_node **stack_a, t_node **stack_b, int print);
void	pa(t_node **stack_a, t_node **stack_b, int print);

//SORT
void	three_sort(t_node **stack_a);
void	stack_sort(t_node **stack_a, t_node **stack_b);

//SORT HELPER
void	set_cost(t_node **stack_a);
void	analyze_cost(t_node **stack_a, t_node **stack_b);
void	min_to_top(t_node **stack_n);
void	move_a(t_node **stack_a, t_node **stack_b);
void	move_b(t_node **stack_a, t_node **stack_b);
void	rise_value_b(t_node **stack_b, t_node *target);
void	rise_value_a(t_node **stack_a, t_node *target);

//DEBUG
void	print_linked_list(t_node *lst);
void	debug_print_list(t_node *stack_n);

//CHECKER
int		checker_verify(char *str);
void	exit_safe(char *msg, char *str);

#endif