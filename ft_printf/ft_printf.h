/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:12 by aaamam            #+#    #+#             */
/*   Updated: 2023/11/23 09:00:38 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int			ft_printf(const char *format, ...);
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_printptr(uintptr_t ptr);
int			ft_printhexa(unsigned int num, const char format);
int			ft_datatypes(va_list vl, const char format);
int			ft_putuint(unsigned int nb);
int			ft_intlen(int n);
int			ft_uintlen(unsigned int nb);
int			ft_hexlen(unsigned int num);
int			ft_ptrlen(uintptr_t nb);
void		ft_puthexa(unsigned int num, const char format);
void		ft_putptr(uintptr_t ptr);
char		*ft_uitoa(unsigned int nb);
char		*ft_itoa(int n);
char		*ft_fillrev(char *s, unsigned int number, int len);

#endif
