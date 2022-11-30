/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:27:09 by educlos           #+#    #+#             */
/*   Updated: 2022/11/30 13:31:19 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *rest)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = ft_len_next(rest);
	if (rest[i] == 0)
		return (0);
	str = malloc(sizeof(char) * k + 1);
	if (!str)
		return (NULL);
	while (rest[i] && rest[i] != '\n')
	{
		str[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_get_rest(char *rest)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = ft_strlen(rest) - ft_len_next(rest);
	if (!k)
	{
		free(rest);
		return (NULL);
	}
	str = malloc(sizeof(char) * k + 1);
	if (!str)
		return (NULL);
	k = ft_len_next(rest);
	while (rest[k] != '\0')
		str[i++] = rest[k++];
	str[i] = 0;
	free(rest);
	return (str);
}

char	*ft_get_buff(int fd, char *rest)
{
	char	*buff;
	int		n;

	n = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = 0;
		rest = ft_strjoin(buff, rest);
		if (check(rest))
			n = 0;
	}
	free(buff);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*str;

	str = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest = ft_get_buff(fd, rest);
	if (!rest)
		return (NULL);
	str = ft_get_line(rest);
	rest = ft_get_rest(rest);
	if (!str)
		free(rest);
	return (str);
}
