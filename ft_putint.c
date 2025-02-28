/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:58:07 by sudelory          #+#    #+#             */
/*   Updated: 2025/02/21 17:17:25 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == INT_MIN)
	{
		i += write(1, "-2147483648", 11);
		return (i);
	}
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar(nb % 10 + '0');
	return (i);
}

int	ft_putunsigned_nbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
		i += ft_putunsigned_nbr(nb / 10);
	i += ft_putchar(nb % 10 + '0');
	return (i);
}

int	ft_puthex(unsigned long nb, int base)
{
	int		i;
	char	*hex;

	i = 0;
	if (base == 87)
		hex = "0123456789abcdef";
	else if (base == 55)
		hex = "0123456789ABCDEF";
	else
		return (0);
	if (nb >= 16)
		i += ft_puthex(nb / 16, base);
	i += ft_putchar(hex[nb % 16]);
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
	{
		return (ft_putstr("(nil)"));
	}
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex((unsigned long)ptr, 87);
	return (count);
}
