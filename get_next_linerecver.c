
#include "get_next_line.h"




char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE];
	char *str;
	static int j;
	int i;
	int len;

	str = NULL;
	while (buff[j] != '\0' && j < BUFFER_SIZE)
	{
		str = ft_buffstr(str, buff, &j);
		printf("%d\n", j);
		i = ft_strlen(str);
		if (str[i - 1] == '\n')
		{
			printf("%s\n", str);
            return (str);
		}
	}
	printf("%s\n", str);
	if (read(fd, buff, BUFFER_SIZE) == 0)
	{
            return NULL;
	}
		
		i = 0;
		printf("j = %s\n", str);	
		str = ft_realloc(buff, str, &i);
        i = ft_strlen(str);
		
        if (str[i - 1] == '\n' || !str[i])
            return (str);
	return NULL;
}

int main()
{
	int	fp;
	char *line;

	fp = open("hello", O_RDONLY);
	while (line = get_next_line(fp))
	{
	//	printf("%s", line);
		free(line);
	}
	close(fp);
}