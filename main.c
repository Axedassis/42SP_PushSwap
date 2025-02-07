/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:49:52 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/06 21:10:47 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	input_check(int argc, char **argv);
void	exit_program(void);

int main(int argc, char **argv)
{
	input_check(argc, argv);
	return (0);
}

void	input_check(int argc, char **argv)
{
	if (argc == 1)
		exit (-1);
	if (argc == 2)
		str_check(argv[1]);
	if (argc > 2)
	{
		char	*nbrs;
		int		i;

		i = 1;
		nbrs = "";
		while(i < argc)
		{
			nbr = ft_strjoin(nbr)
		}
	}
}

void	str_check(char *arg)
{
	char	**splited;
	int		i;
	int		c;
	
	i = 0;
	splited = ft_split(arg, ' ');
	while (splited[i])
	{
		c = 0;
		while(splited[i][c])
		{
			if(ft_isdigit(splited[i][c]) != 1)
			{
				i = 0;
				while (splited[i])
				{
					free(splited[i]);
					i++;
				}
				free(splited);
				exit_program();
			}
			c++;
		}
		i++;
	}
}

void	exit_program(void)
{
	ft_printf("Error\n");
	exit (-1);
}
