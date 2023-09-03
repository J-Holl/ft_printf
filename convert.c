/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 01:44:50 by jholl             #+#    #+#             */
/*   Updated: 2021/03/02 17:03:03 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	conv_ui(t_set *set)
{
	char *str;

	if ((set->field >= 0) && (set->attribute >= 0))
		return (-1);
	str = ft_unsigned_itoa(va_arg(set->to_convert, unsigned int));
	if ((set->zero > 0) && (set->precision >= 0))
	{
		set->field = set->zero;
		set->zero = 0;
	}
	if ((set->zero > 0) && (set->attribute >= 0))
		return (free_str(str));
	set->allocated = 1;
	return (print_result(str, set));
}

int	conv_hexa(t_set *set)
{
	char *str;

	if ((set->field >= 0) && (set->attribute >= 0))
		return (-1);
	str = ft_convert_base(ft_unsigned_itoa(va_arg(set->to_convert,
	unsigned int)), "0123456789", "0123456789abcdef");
	if ((set->zero > 0) && (set->precision >= 0))
	{
		set->field = set->zero;
		set->zero = 0;
	}
	if ((set->zero > 0) && (set->attribute >= 0))
		return (free_str(str));
	set->allocated = 1;
	return (print_result(str, set));
}

int	conv_hexa_caps(t_set *set)
{
	char *str;

	if ((set->field >= 0) && (set->attribute >= 0))
		return (-1);
	str = ft_convert_base(ft_unsigned_itoa(va_arg(set->to_convert,
	unsigned int)), "0123456789", "0123456789ABCDEF");
	if ((set->zero > 0) && (set->precision >= 0))
	{
		set->field = set->zero;
		set->zero = 0;
	}
	if ((set->zero > 0) && (set->attribute >= 0))
		return (free_str(str));
	set->allocated = 1;
	return (print_result(str, set));
}

int	conv_int(t_set *set)
{
	char *str;

	if ((set->field >= 0) && (set->attribute >= 0))
		return (-1);
	str = ft_itoa(va_arg(set->to_convert, int));
	if ((set->zero > 0) && (set->precision >= 0))
	{
		set->field = set->zero;
		set->zero = 0;
	}
	if ((set->zero > 0) && (set->attribute >= 0))
		return (free_str(str));
	set->allocated = 1;
	return (print_result(str, set));
}

int	conv_ptr(t_set *set)
{
	char *str;

	if ((set->field >= 0) && (set->attribute >= 0))
		return (-1);
	str = ft_convert_base(ft_usll_itoa(va_arg(set->to_convert,
	unsigned long long)), "0123456789", "0123456789abcdef");
	if ((set->zero > 0) && (set->precision >= 0))
	{
		set->field = set->zero;
		set->zero = 0;
	}
	if ((set->zero > 0) && (set->attribute >= 0))
		return (free_str(str));
	set->allocated = 1;
	set->hexa = 1;
	return (print_result(str, set));
}
