/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:33:36 by jholl             #+#    #+#             */
/*   Updated: 2021/03/02 15:12:14 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	rec_zero(char *s, t_set *set)
{
	set->zero = 0;
	set->i++;
	if (s[set->i] == '*')
	{
		set->zero = va_arg(set->to_convert, int);
		if (set->zero < 0)
		{
			set->attribute = -set->zero;
			set->zero = -1;
		}
		set->i++;
		return (0);
	}
	while (ft_isdigit(s[set->i]))
	{
		set->zero *= 10;
		set->zero += s[set->i] - '0';
		set->i++;
	}
	return (0);
}

int	rec_field(char *s, t_set *set)
{
	int temp;

	temp = 0;
	set->field = 0;
	if (s[set->i] == '*')
		return (rec_field_split(set, temp));
	while (ft_isdigit(s[set->i]))
	{
		set->field *= 10;
		set->field += s[set->i] - '0';
		set->i++;
	}
	return (0);
}

int	rec_field_split(t_set *set, int temp)
{
	temp = va_arg(set->to_convert, int);
	set->i++;
	if (temp < 0)
	{
		set->attribute = -temp;
		set->field = -1;
		return (0);
	}
	else
	{
		set->field = temp;
		if (set->attribute == 0)
		{
			set->attribute = set->field;
			set->field = -1;
		}
	}
	return (0);
}

int	rec_precision(char *s, t_set *set)
{
	set->i++;
	set->precision = 0;
	if (s[set->i] == '*')
	{
		set->precision = va_arg(set->to_convert, int);
		set->i++;
		if (set->precision < 0)
			set->precision = -1;
		return (0);
	}
	while (ft_isdigit(s[set->i]))
	{
		set->precision *= 10;
		set->precision += s[set->i] - '0';
		set->i++;
	}
	return (0);
}

int	rec_attribute(char *s, t_set *set)
{
	set->i++;
	set->attribute = 0;
	if (s[set->i] == '*')
	{
		set->attribute = va_arg(set->to_convert, int);
		if (set->attribute < 0)
			set->attribute = -set->attribute;
		set->i++;
		return (0);
	}
	while (ft_isdigit(s[set->i]))
	{
		set->attribute *= 10;
		set->attribute += s[set->i] - '0';
		set->i++;
	}
	return (0);
}
