/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:53:14 by paul              #+#    #+#             */
/*   Updated: 2022/05/18 16:40:59 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

size_t	ft_printhex(unsigned long x, int prefix, int cap)
{
	size_t	len;
	char	*base;

	len = 0;
	if (prefix)
		len += write(1, "0x", 2);
	if (!cap)
		base = "0123456789abcdef";
	if (cap)
		base = "0123456789ABCDEF";
	if (x > 15)
		len += ft_printhex((x / 16), 0, cap);
	len += write (1, &base[x % 16], 1);
	return (len);
}

size_t	ft_printnbr(long long nbr)
{
	size_t	len;

	len = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		len++;
		len += ft_printnbr(nbr *(-1));
	}
	else if (nbr >= 0 && nbr <= 9)
		len += ft_printchar(nbr + 48);
	else
	{
		len += ft_printnbr(nbr / 10);
		len += ft_printnbr(nbr % 10);
	}
	return (len);
}

size_t	ft_printstr(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		ft_printchar(str[i++]);
	return (i);
}
