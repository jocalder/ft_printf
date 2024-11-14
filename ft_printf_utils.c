/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:38:47 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/28 15:22:54 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	int	i;

	i = 0;
	i += (write(1, &c, 1));
	return (i);
}

int	ft_putstr(const char *s)
{
	int	i;

	if (s == NULL)
	{
		return (write(1, "(null)", 6));
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
	}
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	str[10];
	int		len;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_unsigned(n / 10);
	str[0] = (n % 10 + '0');
	len += write(1, &str[0], 1);
	return (len);
}

int	ft_putnbrhex(unsigned long n, const char *base)
{
	char	strhex[16];
	int		len;

	len = 0;
	if (n >= 16)
		len += ft_putnbrhex(n / 16, base);
	strhex[0] = base[n % 16];
	len += write(1, &strhex[0], 1);
	return (len);
}
