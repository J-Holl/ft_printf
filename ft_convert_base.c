/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:33:27 by jholl             #+#    #+#             */
/*   Updated: 2021/03/02 15:09:39 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_nbrbase(unsigned long long nbr, int base_size,
		char *base, char *new)
{
	if (nbr < (unsigned long long)base_size)
	{
		*new = base[nbr];
	}
	else
	{
		ft_print_nbrbase(nbr / base_size, base_size, base, new - 1);
		*new = base[nbr % base_size];
	}
}

void	nbr_alphabet_base(unsigned long long nbr, int base_size,
		unsigned long long *count)
{
	*count = *count + 1;
	if (!(nbr < (unsigned long long)base_size))
	{
		nbr_alphabet_base(nbr / base_size, base_size, count);
	}
}

char	*ft_putnbr_base(unsigned long long nbr, char *base)
{
	int					base_size;
	unsigned long long	str_size;
	char				*convert_base;
	unsigned long long	*ptr_count;

	ptr_count = &str_size;
	str_size = 0;
	base_size = ft_strlen1(base);
	nbr_alphabet_base((long)nbr, base_size, ptr_count);
	str_size = *ptr_count;
	convert_base = (char *)malloc(sizeof(char) * (str_size + 1));
	if (convert_base == NULL)
		return (NULL);
	convert_base[str_size] = '\0';
	convert_base += (str_size - 1);
	ft_print_nbrbase((long)nbr, base_size, base, convert_base);
	convert_base -= (str_size - 1);
	return (convert_base);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned long long	dec_nbr;
	char				*convert_base;

	if (!nbr)
		return (NULL);
	if (!(is_base_valid(base_from)))
		return (NULL);
	if (!(is_base_valid(base_to)))
		return (NULL);
	dec_nbr = ft_atoi_base(nbr, base_from);
	convert_base = ft_putnbr_base(dec_nbr, base_to);
	if (nbr)
	{
		free(nbr);
		nbr = NULL;
	}
	return (convert_base);
}
