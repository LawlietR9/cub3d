/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:04:31 by kenito            #+#    #+#             */
/*   Updated: 2023/10/02 22:54:39 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	i;

	i = 0;
	if (!s && !len)
		return (NULL);
	if (!*to_find)
		return ((char *)s);
	while (s[i] && i < len)
	{
		if (ft_strncmp(&s[i], to_find, ft_strlen(to_find)) == 0
			&& i + ft_strlen(to_find) <= len)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

// #include <string.h>
// int main()
// {
// 	char *str = "libft-test-tokyo";
// 	printf("%s\n", ft_strnstr(str, "libft-test-tokyo", 1));
// 	printf("%s\n", strnstr(str, "libft-test-tokyo", 1));
// }
