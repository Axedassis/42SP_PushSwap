/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:58:48 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/07 15:00:38 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	str_check(char *arg);
static void	str_many_check(int argc, char **argv);
static void	check_check(int argc, char **argv);


void	input_check(int argc, char **argv)
{
	if (argc == 1)
		exit (-1);
	if (argc == 2)
		str_check(argv[1]);
	if (argc > 2)
	{
		check_check(argc, argv);
		str_many_check(argc, argv);
	}
}

static void	check_check(int argc, char **argv)
{
	int		i;
	int		c;
	char	**splited;

	i = 1;
	c = 0;
	while (i < argc)
	{
		c = 0;
		splited = ft_split(argv[i], ' ');
		if (!splited)
			exit_program();
		while(splited[c])
			c++;
		if (c != 1)
			exit_program();
		i++;
	}
}

static void	str_many_check(int argc, char **argv)
{
	int		str_len;
	int		i;
	int		tmp_i;
	int		c;

	i = 1;
	c = 0;
	str_len = 0;
	if (argc > 3)
	{
		while(i < argc)
		{
			str_len = ft_strlen(argv[i]);
			
			tmp_i = 0;
			while (tmp_i < str_len)
			{
				if(argv[i][tmp_i] == '+' || argv[i][tmp_i] == '-')
					if (ft_isdigit(argv[i][tmp_i + 1]) == 0)
						exit_program();
				if (ft_isdigit(argv[i][tmp_i]) == 0)
					exit_program();
				tmp_i++;
			}
			i++;
		}
	}
}

static void	str_check(char *arg)
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
			if(splited[i][c] == '+' || splited[i][c] == '-')
				if (ft_isdigit(splited[i][c + 1]) == 0)
					exit_program();
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
