/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:43:59 by kenito            #+#    #+#             */
/*   Updated: 2023/09/27 19:19:53 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		len;
	int		is_negative;

	is_negative = 0;
	len = ft_nbrlen(n);
	if (n < 0)
		is_negative = 1;
	len += is_negative;
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	while (len--)
	{
		dst[len] = (n % 10) * (1 - 2 * is_negative) + '0';
		n /= 10;
	}
	if (is_negative)
		dst[0] = '-';
	return (dst);
}
