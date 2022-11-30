#include "get_next_line.h"

int	ft_len_next(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
	{
		i++;
	}
	if (str[i] == '\n')
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *buff, char *rest)
{
	char	*str;
	int		i;
	int		u;

	u = 0;
	i = 0;
	if (!buff && !rest)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(rest)) + 1);
	if (!str)
		return (0);
	if (rest)
	{
		while (rest[u])
			str[i++] = rest[u++];
	}
	u = 0;
	while (buff[u])
		str[i++] = buff[u++];
	str[i] = 0;
	if (rest)
		free(rest);
	return (str);
}

int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}