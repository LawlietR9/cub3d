/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:09:40 by kenito            #+#    #+#             */
/*   Updated: 2023/09/20 20:09:40 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		if (result > LONG_MAX / 10)
			return ((-1 - sign) / 2);
		result = result * 10 + *str - '0';
		if (sign == 1 && result >= (unsigned long)LONG_MAX)
			return (-1);
		if (sign == -1 && result >= (unsigned long)LONG_MAX + 1)
			return (0);
		str++;
	}
	return (sign * result);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("ft_atoi: %d\n", ft_atoi(argv[1]));
// 		printf("atoi: %d\n", atoi(argv[1]));
// 	}
// 	return (0);
// }
