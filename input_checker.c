/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:23:50 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/19 12:32:24 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char			*init_str(int argc, char **argv);
long			*check_input(char *str, int *size);
static void		check_char(char *letter, char **splited);
static long		*init_nbrs(char **splited, int size);

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

long	*check_input(char *str, int *size)
{
	char	**splited;
	long	*pts;
	int		i;
	int		c;

	i = 0;
	splited = ft_split(str, ' ');
	free (str);
	if (!splited)
		exit (-1);
	while (splited[i])
	{
		c = 0;
		(*size)++;
		while (splited[i][c])
		{
			check_char(&splited[i][c], splited);
			c++;
		}
		i++;
	}
	pts = init_nbrs(splited, i);
	if (pts == NULL)
		exit (-1);
	return (pts);
}

static void	check_char(char *letter, char **splited)
{
	int		bin;
	char	*tmp_ptr;

	bin = 0;
	if (ft_isdigit(*letter) == 0 && bin == 0)
		bin = -1;
	if ((*letter == '-' || *letter == '+') && bin == 0)
		if (ft_isdigit(*(++letter)) == 0)
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

static long	*init_nbrs(char **splited, int size)
{
	long		*pts;
	long		i;

	i = 0;
	pts = (long *)malloc(sizeof(long) * (size + 1));
	if (!pts)
	{
		free_splited(splited);
		exit(-1);
	}
	while (splited[i])
	{
		pts[i] = ft_atoi(splited[i]);
		free(splited[i]);
		i++;
	}
	pts[i] = '\0';
	free(splited);
	return (pts);
}
