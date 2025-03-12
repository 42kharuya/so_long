/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <kharuya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:59:44 by kharuya           #+#    #+#             */
/*   Updated: 2024/12/08 01:01:42 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_d(int d)
{
	char	*res;
	int		print_char;

	res = ft_itoa(d);
	if (!res)
		return (-1);
	print_char = ft_printf_s(res);
	free(res);
	return (print_char);
}
