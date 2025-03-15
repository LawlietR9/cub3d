/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:25:12 by kenito            #+#    #+#             */
/*   Updated: 2023/11/05 20:22:47 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	char	*ptr;
// 	char	ch;

// 	if (!s)
// 		return (NULL);
// 	ptr = (char *)s;
// 	ch = (char)c;
// 	while (*ptr)
// 	{
// 		if (*ptr == ch)
// 			return (ptr);
// 		ptr++;
// 	}
// 	if (*ptr == ch)
// 		return (ptr);
// 	return (NULL);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	n;

// 	n = 0;
// 	while (str[n])
// 		n++;
// 	return (n);
// }

// char	*ft_substr(const char *s, unsigned int start, size_t len)
// {
// 	char	*dst;
// 	size_t	s_len;

// 	s_len = ft_strlen(s);
// 	if (start >= s_len)
// 	{
// 		dst = (char *)malloc(1);
// 		if (!dst)
// 			return (NULL);
// 		dst[0] = '\0';
// 		return (dst);
// 	}
// 	if (s_len - start < len)
// 		len = s_len - start;
// 	dst = malloc(len + 1);
// 	if (!dst)
// 		return (NULL);
// 	dst[len] = 0;
// 	while (len--)
// 		dst[len] = s[start + len];
// 	return (dst);
// }

char	*join_n_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s1)
	{
		if (!*s2)
			return (NULL);
		s1 = ft_substr("", 0, 1);
	}
	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	j = -1;
	while (s2[++j])
		dst[i + j] = s2[j];
	dst[i + j] = '\0';
	free(s1);
	return (dst);
}
