/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:06 by aaamam            #+#    #+#             */
/*   Updated: 2023/11/22 16:38:06 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_datatypes(va_list vl, const char format)
{
	int	print;

	print = 0;
	if (format == 'c')
		print += ft_putchar(va_arg(vl, int));
	else if (format == 's')
		print += ft_putstr(va_arg(vl, char *));
	else if (format == 'p')
		print += ft_printptr(va_arg(vl, uintptr_t));
	else if (format == 'd' || format == 'i')
		print += ft_putnbr(va_arg(vl, int));
	else if (format == 'u')
		print += ft_putuint(va_arg(vl, unsigned int));
	else if (format == 'x' || format == 'X')
		print += ft_printhexa(va_arg(vl, unsigned int), format);
	else if (format == '%')
		print += ft_putchar('%');
	return (print);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	vl;
	int		print;

	i = 0;
	print = 0;
	va_start(vl, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print += ft_datatypes(vl, format[i + 1]);
			i++;
		}
		else
			print += ft_putchar(format[i]);
		i++;
	}
	va_end(vl);
	return (print);
}
