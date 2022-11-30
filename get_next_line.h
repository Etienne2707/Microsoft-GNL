/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:32:24 by tbelleng          #+#    #+#             */
/*   Updated: 2022/11/29 14:22:38 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *buff, char  *rest);
int     ft_strlen(char *str);
int     ft_len_next(char *str);
int     check(char *str);
char	*ft_get_line(char *rest);
char	*ft_get_rest(char *rest);
char	*ft_get_buff(int fd, char *rest);

#endif
