
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n) //changed
{
	size_t i = 0;
	while (n > i) //changed
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return dest;
}

size_t	ft_strlen( char *s)
{
	size_t ret = 0;
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t size1 = 0;
	if (*s1) //added
		size1 = ft_strlen(*s1);
	char *tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return 0;
	if (*s1) //added
		ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return 1;
}

int	str_append_str(char **s1, char *s2)
{
	return str_append_mem(s1, s2, ft_strlen(s2));
}


char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1] = "";
	char *ret = NULL;

	char *tmp = ft_strchr(buffer, '\n');
	while (!tmp)
	{
		if (!str_append_str(&ret, buffer))
			return NULL;
		int read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret < 0) //added
			return NULL;
		if (read_ret == 0) //added
		{
			buffer[0] = 0;
			break;
		}
		buffer[read_ret] = 0;
		tmp = ft_strchr(buffer, '\n'); //added
	}
	if (tmp)
	{
		if (!str_append_mem(&ret, buffer, tmp - buffer + 1))
		{
			free(ret);
			return NULL;
		}
		ft_memcpy(buffer, tmp + 1, ft_strlen(tmp + 1) + 1);
		return ret;
	}
	if (ret && *ret)
		return ret;
	free(ret);
	return NULL;
}

#include <fcntl.h>

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	int line_count = 1;

	if (fd < 0)
	{
		printf("Error opening file\n");
		return 1;
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", line_count, line);
		free(line);
		line_count++;
	}

	close(fd);
	return 0;
}