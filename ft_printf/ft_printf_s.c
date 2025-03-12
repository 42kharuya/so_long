/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <kharuya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:11:25 by kharuya           #+#    #+#             */
/*   Updated: 2024/12/08 00:52:47 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (write(1, &*(str++), 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_printf_s(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (ft_printstr(str));
}
