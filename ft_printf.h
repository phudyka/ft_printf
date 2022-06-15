/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:14:11 by phudyka           #+#    #+#             */
/*   Updated: 2022/05/18 16:39:26 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

size_t	ft_printchar(char c);
size_t	ft_printstr(const char *str);
size_t	ft_printnbr(long long nbr);
size_t	ft_printhex(unsigned long x, int prefix, int cap);
size_t	ft_parse(va_list arg, char format);
int		ft_printf(const char *format, ...);
#endif
