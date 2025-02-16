/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:09:32 by kenito            #+#    #+#             */
/*   Updated: 2023/09/20 20:09:32 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (ptr_dst < ptr_src)
		ft_memcpy(ptr_dst, ptr_src, len);
	else
	{
		while (len--)
			ptr_dst[len] = ptr_src[len];
	}
	return (dst);
}
