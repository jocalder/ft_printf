/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:45:58 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/28 15:23:28 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stddef.h>

int	ft_putchar(int c);
int	ft_putstr(const char *s);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbrhex(unsigned long n, const char *base);
int	ft_putptr(void *p);
int	myformat(char format, va_list args);
int	ft_printf(const char *format, ...);

#endif
