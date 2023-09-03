/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 04:31:19 by jholl             #+#    #+#             */
/*   Updated: 2021/02/22 14:13:36 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				rcrsv_crt_str1(char *s, unsigned int n)
{
	if (n < 10)
	{
		*s = n + '0';
	}
	else if (n >= 10)
	{
		rcrsv_crt_str1(s - 1, n / 10);
		*s = (n % 10) + '0';
	}
}

unsigned int		count_digit1(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char				*ft_unsigned_itoa(unsigned int n)
{
	unsigned int	count;
	char			*s;

	count = 0;
	count = count_digit1(n);
	if (!(s = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	rcrsv_crt_str1(s + (count - 1), n);
	s[count] = '\0';
	return (s);
}
