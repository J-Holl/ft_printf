/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 02:21:55 by jholl             #+#    #+#             */
/*   Updated: 2021/03/02 15:58:22 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	conv_char(t_set *set)
{
	unsigned char str[2];

	if ((set->field >= 0) && (set->attribute >= 0))
		return (-1);
	if ((set->zero >= 0) || (set->precision >= 1))
		return (-1);
	str[0] = (char)va_arg(set->to_convert, int);
	str[1] = '\0';
	if (*str == '\0')
		set->hexa = 3;
	return (print_result((char *)str, set));
}

int	conv_str(t_set *set)
{
	char *str;
	char *temp;

	str = NULL;
	if ((set->field >= 0) && (set->attribute >= 0))
		return (-1);
	if (set->zero >= 0)
		return (-1);
	temp = (char *)va_arg(set->to_convert, const char *);
	if (temp)
		return (conv_str_split(set, str, temp));
	if (!temp)
		return (conv_str_split1(set, str));
	set->allocated = 1;
	return (print_result(str, set));
}

int	conv_str_split(t_set *set, char *str, char *temp)
{
	if (!(str = (char *)malloc(sizeof(char *) * (ft_strlen(temp) + 1))))
		return (-1);
	ft_strlcpy(str, temp, ft_strlen(temp) + 1);
	if ((set->precision >= 0))
	{
		if ((int)ft_strlen(str) > set->precision)
		{
			str[set->precision] = '\0';
			set->precision = -1;
		}
		else
			set->precision = -1;
	}
	set->allocated = 1;
	return (print_result(str, set));
}

int	conv_str_split1(t_set *set, char *str)
{
	if (!(str = (char *)malloc(sizeof(char *) * (7))))
		return (-1);
	ft_strlcpy(str, "(null)", 7);
	if ((set->precision >= 0))
	{
		if ((int)ft_strlen(str) > set->precision)
		{
			str[set->precision] = '\0';
			set->precision = -1;
		}
		else
			set->precision = -1;
	}
	set->allocated = 1;
	return (print_result(str, set));
}

int	conv_percent(t_set *set)
{
	unsigned char str[2];

	if ((set->field >= 0) && (set->attribute >= 0))
		return (-1);
	if ((set->precision >= 0))
		set->precision = -1;
	str[0] = '%';
	str[1] = '\0';
	return (print_result((char *)str, set));
}
