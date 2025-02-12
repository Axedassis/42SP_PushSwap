/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:26:16 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/12 16:27:22 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
			if (nbrs[j] == nbrs[i])
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
