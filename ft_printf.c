/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:11:01 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/28 15:26:50 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	myformat(char format, va_list args)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		i += (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		i += (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		i += (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		i += (ft_putnbrhex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		i += (ft_putnbrhex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == 'p')
		i += (ft_putptr(va_arg(args, void *)));
	else if (format == '%')
		i += (write(1, "%", 1));
	else
		return (0);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += myformat(*format, args);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int a = 753;
	int c = ' ';
	char *s_s = NULL;
	int printfreturn = printf("%c\n", 'c');
	int ownreturn = ft_printf("%c\n", 'c');
	printf("ownreturn: [%i] printfreturn: [%i]\n\n", ownreturn, printfreturn);
	ownreturn = ft_printf("%s\n", "que onda carnal");
	printfreturn = printf("%s\n", "que onda carnal");
	printf("ownreturn: [%i] printfreturn: [%i]\n\n", ownreturn, printfreturn);
	ownreturn = ft_printf("%d\n", -65);
	printfreturn = printf("%d\n", -65);
	printf("ownreturn: [%i] printfreturn: [%i]\n\n", ownreturn, printfreturn);
	ownreturn = ft_printf("%i\n", 89263);
	printfreturn = printf("%i\n", 89263);
	printf("ownreturn: [%i] printfreturn: [%i]\n\n", ownreturn, printfreturn);
	ownreturn = ft_printf("%u\n", 823938);
	printfreturn = printf("%u\n", 823938);
	printf("ownreturn: [%i] printfreturn: [%i]\n\n", ownreturn, printfreturn);
	ownreturn = ft_printf("%X\n", 255);
	printfreturn = printf("%X\n", 255);
	printf("ownreturn: [%i] printfreturn: [%i]\n\n", ownreturn, printfreturn);
	ownreturn = ft_printf("%x\n", 255);
	printfreturn = printf("%x\n", 255);
	printf("ownreturn: [%i] printfreturn: [%i]\n\n", ownreturn, printfreturn);
	ownreturn = ft_printf("%%\n");
	printfreturn = printf("%%\n");
	printf("ownreturn: [%i] printfreturn: [%i]\n\n", ownreturn, printfreturn);
	ownreturn = ft_printf("%p\n", &a);
	printfreturn = printf("%p\n", &a);
	printf("ownreturn: [%i] printfreturn: [%i]\n\n", ownreturn, printfreturn);
	ownreturn = ft_printf("%p\n", &c);
	printfreturn = printf("%p\n", &c);
	printf("ownreturn: [%i] printfreturn: [%i]\n\n", ownreturn, printfreturn);
	ownreturn = ft_printf("%p\n", NULL);
	printfreturn = printf("%p\n", NULL);
	printf("ownreturn: [%i] printfreturn: [%i]\n\n", ownreturn, printfreturn);
	ownreturn = ft_printf("%s\n", s_s);
	printfreturn = printf("%s\n", s_s);
	printf("ownreturn: [%i] printfreturn: [%i]\n\n", ownreturn, printfreturn);
	
	return 0;
}*/
