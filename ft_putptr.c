/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:24:53 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/28 15:19:36 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	unsigned long	a;
	int				len;

	if (!p)
		return (ft_putstr("(nil)"));
	a = (unsigned long)p;
	len = write(1, "0x", 2);
	if (a == 0)
		len += write(1, "(nil)", 5);
	else
		len += ft_putnbrhex(a, "0123456789abcdef");
	return (len);
}
