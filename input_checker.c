/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:23:50 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/07 18:31:28 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	*init_nbrs(char **splited, int size);
static void	check_char(char *letter,char **splited);
static int	*check_ints(char *str);

char	*init_str(int argc, char **argv)
{
	char	*str;
	char	*tmp_pnt;
	int		i;

	i = 1;
	str = ft_strdup("");
	while (i < argc)
	{
		tmp_pnt = str;
		str = ft_strjoin(str, " ");
		if (!str)
			return (NULL);
		free(tmp_pnt);
		tmp_pnt = str;
		str = ft_strjoin(str, argv[i]);
		if (!str)
			return (NULL);
		free(tmp_pnt);
		i++;
	}
	return (str);
}

int	*check_ints(char *str)
{
	char	**splited;
	int		*pts;
	int		i;
	int		c;

	i = 0;
	splited = ft_split(str,' ');
	if (!splited)
	{
		free (str);
		exit (-1);
	}
	free (str);
	while (splited[i])
	{
		c = 0;
		while(splited[i][c])
		{
			check_char(&splited[i][c], splited);
			c++;
		}
		i++;
	}
	pts = init_nbrs(splited, i);
	if (!pts)
		exit (-1);
	return (pts);
}

static void	check_char(char *letter,char **splited)
{
	int		bin;
	char	*tmp_ptr;
	int		i;

	i = 0;
	bin = 0;
	if (ft_isdigit(*letter) == 0 && bin == 0)
		bin = -1;
	if ((*letter == '-' || *letter == '+') && bin == 0)
		if(ft_isdigit(*(++letter)) == 0)
			bin = -1;
	if ((*letter == '-' || *letter == '+') && bin == 0)
	{
		tmp_ptr = letter++;
		if (*tmp_ptr == '-' || *tmp_ptr == '+')
			bin = -1;
	}
	if (*letter == ' ')
		bin = -1;
	if (bin == -1)
	{
		free_splited(splited);
		ft_printf("Error\n");
		exit(-1);
	}
}

static int	*init_nbrs(char **splited, int size)
{
	int		*pts;
	int		i;

	i = 0;
	pts = (int *)malloc(sizeof(int) * (size + 1));
	if (!pts)
	{
		free_splited(splited);
		exit(-1);
	}
	while (splited[i])
	{
		pts[i] = ft_atoi(splited[i]);
		if (!pts[i])
		{
			free_splited(splited);
			return (NULL);
		}
		free(splited[i]);
		i++;
	}
	free(splited);
	return (pts);
}
