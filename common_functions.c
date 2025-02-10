/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:26:16 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/10 14:45:11 by lsilva-x         ###   ########.fr       */
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

void	check_nbrs(int *nbrs)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (nbrs[i])
	{
		j = i + 1;
		while (nbrs[j])
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
