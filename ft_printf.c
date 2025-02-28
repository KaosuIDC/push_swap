/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:50:51 by sudelory          #+#    #+#             */
/*   Updated: 2025/02/21 17:17:03 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_input(const char *input, va_list args)
{
	if (*input == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*input == 's')
		return (ft_putstr((va_arg(args, char *))));
	else if (*input == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (*input == 'd' || *input == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*input == 'u')
		return (ft_putunsigned_nbr(va_arg(args, unsigned int)));
	else if (*input == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 87));
	else if (*input == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 55));
	else if (*input == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	int				count;
	int				check;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		check = 0;
		if (format[i] == '%')
		{
			check = check_input(&format[++i], args);
			if (check < 0)
				return (-1);
			count += check;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (va_end(args), count);
}
