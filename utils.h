/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:50:28 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/10 14:44:46 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/includes/libft.h"

void	free_splited(char **splited);
char	*init_str(int argc, char **argv);
int		*check_ints(char *str);
void	check_nbrs(int *nbrs);

# endif