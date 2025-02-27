/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:26:24 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/19 18:15:31 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*get_next_line(int fd, int cod)
{
	static char	*buffer;
	char		*line;

	if (cod == -42)
	{
		free(buffer);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = gnl_content(fd, buffer);
	if (!buffer)
		return (NULL);
	line = gnl_line(buffer);
	buffer = gnl_rest(buffer);
	return (line);
}
