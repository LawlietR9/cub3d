/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:39:25 by kenito            #+#    #+#             */
/*   Updated: 2023/11/05 20:26:36 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_str(int fd, char *str)
{
	int		n;
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + (size_t)1);
	if (!buf)
		return (NULL);
	n = 1;
	while (!ft_strchr(str, '\n') && n)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[n] = '\0';
		str = join_n_free(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_line(char *str)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = ft_substr(str, 0, ++i);
	else
		line = ft_substr(str, 0, i);
	return (line);
}

char	*next_str(char *str)
{
	char	*next;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	next = ft_substr(str, i + 1, ft_strlen(str) - i + 1);
	free(str);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE < 1)
		return (NULL);
	str = read_str(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	if (!line)
	{
		free(str);
		return (NULL);
	}
	str = next_str(str);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	
	return (line);
}

// #include <fcntl.h>
// int main()
// {
// 	char *line;
// 	int	i;

// 	int	fd = open("../test.txt", O_RDONLY);
// 	i = 1;
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("line[%d] = %s", i, line);
// 		// printf("length = %d\n", (int)ft_strlen(line));
// 		if (line)
// 			free(line);
// 		i++;
// 	}
// 	close(fd);
// 	printf("line[%d] = %s\n", i, line);
// }
