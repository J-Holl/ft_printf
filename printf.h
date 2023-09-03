/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:12:42 by jholl             #+#    #+#             */
/*   Updated: 2021/03/02 17:00:10 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_set
{
	va_list			to_convert;
	size_t			i;
	size_t			printed;
	size_t			size;
	int				precision;
	int				attribute;
	int				zero;
	int				field;
	int				allocated;
	int				hexa;
}					t_set;

int					ft_printf(const char *s, ...);
int					read_sharp(char *s, t_set *set);
int					is_legit_option(char *s, t_set *set);
int					read_s(char *s, t_set *set);

size_t				ft_strlen(char *s);
unsigned long long	ft_strlen1(char *str);
int					is_base_valid(char *base);
int					check_base_position(char c, char *base);
unsigned long long	ft_atoi_base(char *str, char *base);
void				ft_print_nbrbase(unsigned long long nbr, int base_size,
					char *base, char *new);
void				nbr_alphabet_base(unsigned long long nbr, int base_size,
					unsigned long long *count);
char				*ft_putnbr_base(unsigned long long nbr, char *base);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);

int					conv_char(t_set *set);
int					conv_str(t_set *set);
int					conv_str_split(t_set *set, char *str, char *temp);
int					conv_str_split1(t_set *set, char *str);
int					conv_hexa(t_set *set);
int					conv_hexa_caps(t_set *set);
int					conv_ui(t_set *set);
int					conv_int(t_set *set);
int					conv_ptr(t_set *set);
int					conv_percent(t_set *set);

int					rec_zero(char *s, t_set *set);
int					rec_field(char *s, t_set *set);
int					rec_field_split(t_set *set, int temp);
int					rec_precision(char *s, t_set *set);
int					rec_attribute(char *s, t_set *set);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_itoa(int n);
char				*ft_usll_itoa(unsigned long long n);
char				*ft_unsigned_itoa(unsigned int n);
void				ft_putstr(char *s, t_set *set);
void				ft_putchar(char c, t_set *set);
void				ft_put_n_char(char c, int n, t_set *set);

int					ft_isdigit(char c);
int					ft_isalpha(char c);

void				ini_set(t_set *set);
int					free_str(char *s);

void				special_case(char *to_print, t_set *set);
void				print_result2(char *to_print, t_set *set, int i, int j);
int					print_result1(char *to_print, t_set *set, int i, int j);
int					print_result(char *to_print, t_set *set);
#endif
