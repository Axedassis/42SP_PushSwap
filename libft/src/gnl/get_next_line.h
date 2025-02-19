/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:27:50 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/19 18:15:40 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd, int cod);
char	*gnl_content(int fd, char *res);
char	*gnl_line(char *buffer);
char	*gnl_rest(char *buffer);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t cnt, size_t size);

#endif