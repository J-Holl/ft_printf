/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:44:57 by jholl             #+#    #+#             */
/*   Updated: 2021/03/02 16:59:36 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ini_set(t_set *set)
{
	set->precision = -1;
	set->attribute = -1;
	set->zero = -1;
	set->field = -1;
	set->allocated = 0;
	set->hexa = 0;
	set->size = 0;
}

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int		free_str(char *s)
{
	if (s)
		free(s);
	s = NULL;
	return (-1);
}
