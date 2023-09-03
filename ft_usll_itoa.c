/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usll_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:36:25 by jholl             #+#    #+#             */
/*   Updated: 2021/02/23 11:36:39 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				rcrsv_crt_str2(char *s, unsigned long long n)
{
	if (n < 10)
	{
		*s = n + '0';
	}
	else if (n >= 10)
	{
		rcrsv_crt_str2(s - 1, n / 10);
		*s = (n % 10) + '0';
	}
}

unsigned long long	count_digit2(unsigned long long n)
{
	unsigned long long	count;

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

char				*ft_usll_itoa(unsigned long long n)
{
	unsigned long long	count;
	char				*s;

	count = 0;
	count = count_digit2(n);
	if (!(s = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	rcrsv_crt_str2(s + (count - 1), n);
	s[count] = '\0';
	return (s);
}
