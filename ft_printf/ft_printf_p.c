/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <kharuya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:03:30 by kharuya           #+#    #+#             */
/*   Updated: 2024/12/08 00:50:31 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_address(uintptr_t ptr_data)
{
	const char	*hex_num;
	char		res[16 + 1];
	int			index;
	int			start;

	hex_num = HEX_LOWER;
	index = 16;
	res[index--] = '\0';
	if (ptr_data == 0)
		res[index--] = '0';
	while (ptr_data)
	{
		res[index--] = hex_num[ptr_data % 16];
		ptr_data /= 16;
	}
	start = index + 1;
	while (res[start])
	{
		if (ft_printf_c(res[start++]) == -1)
			return (-1);
	}
	return (16 - index - 1);
}

int	ft_printf_p(void *ptr)
{
	uintptr_t	ptr_data;
	int			count;
	int			error_check;

	if (!ptr)
		return (ft_printf_s("(nil)"));
	ptr_data = (uintptr_t)ptr;
	count = ft_printf_s("0x");
	if (count == -1)
		return (-1);
	error_check = ft_printf_address(ptr_data);
	if (error_check == -1)
		return (-1);
	count += error_check;
	return (count);
}
