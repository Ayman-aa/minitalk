/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:34:12 by aaamam            #+#    #+#             */
/*   Updated: 2023/11/22 23:34:12 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}

int	ft_putuint(unsigned int nb)
{
	int		print;
	char	*str;

	print = 0;
	if (nb == 0)
		print += write(1, "0", 1);
	else
	{
		str = ft_uitoa(nb);
		print += ft_putstr(str);
		free(str);
	}
	return (print);
}

int	ft_printptr(uintptr_t ptr)
{
	int	print;

	print = 0;
	print += write(1, "0x", 2);
	if (ptr == 0)
		print += write(1, "0", 1);
	else
	{
		print += ft_ptrlen(ptr);
		ft_putptr(ptr);
	}
	return (print);
}

int	ft_printhexa(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_puthexa(num, format);
	return (ft_hexlen(num));
}
