/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 02:24:42 by jholl             #+#    #+#             */
/*   Updated: 2021/03/02 15:20:13 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			print_result(char *to_print, t_set *set)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*to_print == '0')
		special_case(to_print, set);
	set->size = ft_strlen(to_print);
	if (set->hexa == 3)
		set->size = 1;
	if (set->hexa == 1)
		set->size += 2;
	if (set->zero >= 0)
		i = set->zero - set->size;
	if (set->precision >= 0)
		i = set->precision - set->size;
	if (set->precision >= 0 && set->hexa == 1)
		i += 2;
	if (*to_print == '-' && set->precision >= 0)
		i++;
	if (set->attribute >= 0)
		j = set->attribute - set->size;
	return (print_result1(to_print, set, i, j));
}

int			print_result1(char *to_print, t_set *set, int i, int j)
{
	if (set->field >= 0)
		j = set->field - set->size;
	if (i > 0 && j >= 0 && set->precision >= 0)
		j -= i;
	if ((set->field >= 0) && j > 0)
		ft_put_n_char(' ', j, set);
	if (set->hexa == 1)
		ft_putstr("0x", set);
	if (*to_print == '-')
		ft_putchar('-', set);
	if (((set->zero >= 0) || (set->precision >= 0)) && i > 0)
		ft_put_n_char('0', i, set);
	if (set->hexa == 3)
		ft_putchar('\0', set);
	if (*to_print == '-')
		ft_putstr(to_print + 1, set);
	else
		ft_putstr(to_print, set);
	if ((set->attribute >= 0) && j > 0)
		ft_put_n_char(' ', j, set);
	if (set->allocated)
		free_str(to_print);
	return (0);
}

void		special_case(char *to_print, t_set *set)
{
	if (set->precision == 0)
	{
		*to_print = '\0';
	}
}
