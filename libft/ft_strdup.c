/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:27:34 by kenito            #+#    #+#             */
/*   Updated: 2023/09/24 06:27:34 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}
