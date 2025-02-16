/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:40:22 by kenito            #+#    #+#             */
/*   Updated: 2023/10/04 19:38:04 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

static char	**free_all(char **dst)
{
	while (*dst)
	{
		free(*dst);
		dst++;
	}
	free(dst);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**dst;
	size_t	i;
	size_t	j;
	size_t	n;

	dst = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!dst)
		return (NULL);
	n = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		dst[n] = ft_substr(s, i, j);
		if (!dst[n])
			return (free_all(dst));
		i += j + (s[i + j] == c);
		n++;
	}
	dst[n] = NULL;
	return (dst);
}

// int main()
// {
// 	char **dst;
// 	dst = ft_split(",,hello,,,world,,,42,,,tokyo,", ',');
// 	printf("%s\n", dst[0]);
// 	printf("%s\n", dst[1]);
// 	printf("%s\n", dst[2]);
// 	// dst = ft_split("hello world 42 tokyo", ' ');
// 	// printf("%s\n", dst[0]);
// 	// printf("%s\n", dst[1]);
// 	// printf("%s\n", dst[2]);
// 	return (0);
// }
