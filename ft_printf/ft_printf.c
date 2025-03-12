/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <kharuya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 02:58:44 by kharuya           #+#    #+#             */
/*   Updated: 2024/12/08 00:54:07 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_printf_format(const char format, va_list args)
{
	int	print_char;

	print_char = 0;
	if (format == 'c')
		print_char += ft_printf_c(va_arg(args, int));
	else if (format == 's')
		print_char += ft_printf_s(va_arg(args, char *));
	else if (format == 'p')
		print_char += ft_printf_p(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_char += ft_printf_d(va_arg(args, int));
	else if (format == 'u')
		print_char += ft_printf_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_char += ft_printf_x(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_char += ft_printf_c('%');
	return (print_char);
}

int	ft_printf(const	char *format, ...)
{
	va_list	args;
	int		count;
	int		error_check;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		error_check = 0;
		if (*format != '%')
			error_check = ft_printf_c(*format);
		else if (*format == '%' && *(format + 1))
			error_check = ft_printf_format(*(++format), args);
		if (error_check == -1)
			return (-1);
		count += error_check;
		format++;
	}
	va_end(args);
	return (count);
}
