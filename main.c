/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:59:32 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/07 18:30:04 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

	return (0);
}
