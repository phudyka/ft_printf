/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:27:29 by phudyka           #+#    #+#             */
/*   Updated: 2022/05/18 16:16:45 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_parse(va_list arg, char format)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(arg, int));
	else if (format == 's')
		len += ft_printstr(va_arg(arg, char *));
	else if (format == 'p')
		len += ft_printhex(va_arg(arg, unsigned long), 1, 0);
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(arg, int));
	else if (format == 'u')
		len += ft_printnbr(va_arg(arg, unsigned int));
	else if (format == 'x')
		len += ft_printhex(va_arg(arg, unsigned int), 0, 0);
	else if (format == 'X')
		len += ft_printhex(va_arg(arg, unsigned int), 0, 1);
	else if (format == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	len;

	len = 0;
	va_start(arg, format);
	if (!format)
	{
		va_end(arg);
		return (0);
	}
	while (*format)
	{
		if (*format == '%')
			len += ft_parse(arg, *++format);
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(arg);
	printf("%zu", len);
	return (len);
}

int main()
{
	unsigned int i =  -123456;
	printf("%i\n", i);	
	ft_printf("%i\n", i);

	return 0;
}