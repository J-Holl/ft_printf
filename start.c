/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 03:21:32 by jholl             #+#    #+#             */
/*   Updated: 2021/02/23 12:50:25 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_legit_option(char *s, t_set *set)
{
	if (s[set->i] == '0' || s[set->i] == '.' || s[set->i] == '-' ||
	s[set->i] == '*' || ft_isdigit(s[set->i]))
		return (1);
	return (0);
}

int		redirect_convert(char *s, t_set *set)
{
	if (s[set->i] == 'c')
		return (conv_char(set));
	if (s[set->i] == 's')
		return (conv_str(set));
	if (s[set->i] == 'u')
		return (conv_ui(set));
	if (s[set->i] == 'x')
		return (conv_hexa(set));
	if (s[set->i] == 'X')
		return (conv_hexa_caps(set));
	if (s[set->i] == 'i' || s[set->i] == 'd')
		return (conv_int(set));
	if (s[set->i] == 'p')
		return (conv_ptr(set));
	if (s[set->i] == '%')
		return (conv_percent(set));
	return (-1);
}

int		read_sharp(char *s, t_set *set)
{
	set->i++;
	while (is_legit_option(s, set))
	{
		if (s[set->i] == '0')
			if (rec_zero(s, set) < 0)
				return (-1);
		if (ft_isdigit(s[set->i]) || s[set->i] == '*')
			if (rec_field(s, set) < 0)
				return (-1);
		if (s[set->i] == '-')
			if (rec_attribute(s, set) < 0)
				return (-1);
		if (s[set->i] == '.')
			if (rec_precision(s, set) < 0)
				return (-1);
	}
	return (0);
}

int		read_s(char *s, t_set *set)
{
	while (s[set->i])
	{
		ini_set(set);
		if (s[set->i] == '%')
		{
			if (read_sharp(s, set) < 0)
				return (-1);
			if (redirect_convert(s, set) < 0)
				return (-1);
		}
		else if (s[set->i])
			ft_putchar(s[set->i], set);
		set->i++;
	}
	return (1);
}

int		ft_printf(const char *s, ...)
{
	t_set	set;
	int		sum_printed;

	va_start(set.to_convert, s);
	set.i = 0;
	set.printed = 0;
	sum_printed = read_s((char *)s, &set);
	if (sum_printed < 0)
		return (-1);
	va_end(set.to_convert);
	return (set.printed);
}
