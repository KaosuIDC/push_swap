/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:57:10 by sudelory          #+#    #+#             */
/*   Updated: 2025/02/28 03:13:18 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		rev;
	int		count;

	i = 0;
	rev = 1;
	count = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			rev *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = count * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == ' ' && str[i + 1] == ' ')
		error_and_exit();
	return (count * rev);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && is_digit(*str))
	{
		if (result > result * 10 + (*str - '0'))
			error_and_exit();
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	check_range(char *str)
{
	long	num;

	num = ft_atol(str);
	return (num >= INT_MIN && num <= INT_MAX);
}
