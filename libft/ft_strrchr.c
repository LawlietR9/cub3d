/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:09:53 by kenito            #+#    #+#             */
/*   Updated: 2023/09/23 17:08:48 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	while (ptr >= s)
	{
		if (*ptr == (char)c)
			return ((char *)ptr);
		ptr--;
	}
	return (NULL);
}
