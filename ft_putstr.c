/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:52:07 by jholl             #+#    #+#             */
/*   Updated: 2021/02/21 05:27:36 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(char *s, t_set *set)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s++, 1);
		set->printed++;
	}
}

void	ft_putchar(char c, t_set *set)
{
	write(1, &c, 1);
	set->printed++;
}

void	ft_put_n_char(char c, int n, t_set *set)
{
	while (n--)
	{
		write(1, &c, 1);
		set->printed++;
	}
}
