/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:11:05 by kenito            #+#    #+#             */
/*   Updated: 2023/09/20 20:11:05 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	ch;

	ptr = (char *)s;
	ch = (char)c;
	while (*ptr)
	{
		if (*ptr == ch)
			return (ptr);
		ptr++;
	}
	if (*ptr == ch)
		return (ptr);
	return (NULL);
}
