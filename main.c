/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:59:32 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/10 14:47:42 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char **argv)
{
	char	*str;
	int		*nbrs;

	if (argc == 1)
		return (-1);
	str = init_str(argc, argv);
	if (!str)
		return (-1);
	nbrs = check_ints(str);
	check_nbrs(nbrs);
	return (0);
}
