/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 04:31:19 by jholl             #+#    #+#             */
/*   Updated: 2021/02/18 18:16:37 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		rcrsv_crt_str(char *s, long n)
{
	if (n < 10)
	{
		*s = n + '0';
	}
	else if (n >= 10)
	{
		rcrsv_crt_str(s - 1, n / 10);
		*s = (n % 10) + '0';
	}
}

static int		count_digit(long n, int count)
{
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int		count;
	long	n_long;
	char	*s;

	count = 0;
	n_long = (long)n;
	if (n_long <= 0)
	{
		n_long *= -1;
		count++;
	}
	count = count_digit(n_long, count);
	if (!(s = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	rcrsv_crt_str(s + (count - 1), n_long);
	if (n < 0)
		s[0] = '-';
	s[count] = '\0';
	return (s);
}
