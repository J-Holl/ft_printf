/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:36:27 by jholl             #+#    #+#             */
/*   Updated: 2021/02/23 15:37:57 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long		ft_strlen1(char *str)
{
	unsigned long long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int						is_base_valid(char *base)
{
	int					i;
	int					j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = 0;
		while (base[i] && base[i + j])
		{
			j++;
			if (base[i] == base[i + j] || base[i] == '+'
			|| base[i] == '-' || base[i] < 33 || base[i] > 126)
				return (0);
		}
		i++;
	}
	return (1);
}

int						check_base_position(char c, char *base)
{
	unsigned long long	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		else
			i++;
	}
	return (-1);
}

unsigned long long		ft_atoi_base(char *str, char *base)
{
	unsigned long long	i;
	unsigned long long	result;

	i = 0;
	result = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] != '\0' && (check_base_position(str[i], base) != -1))
	{
		if (check_base_position(str[i], base) == -1)
			return (0);
		result = result * ft_strlen1(base) + check_base_position(str[i], base);
		i++;
	}
	return (result);
}
