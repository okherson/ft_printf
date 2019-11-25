/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:44:28 by okherson          #+#    #+#             */
/*   Updated: 2019/04/18 19:54:40 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct			s_f
{
	int					o;
	int					minus;
	int					plus;
	int					grill;
	int					space;
	int					width;
	int					accuracy;
	int					size;
	char				type;
	int					undef;
}						t_f;

typedef struct			s_t
{
	va_list				ap;
	t_f					f;
	char				b[2042];
	char				*s;
	int					sp;
	int					bp;
	int					tl;
}						t_t;

typedef struct			s_float
{
	long int			fp;
	long double			sp;
	char				*str_fp;
	char				*str_sp;
	int					len_fp;
}						t_float;

int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
void					ft_putchar(char c);
void					ft_putnbr(int n);
void					ft_putstr(char const *s);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strdup(char *s1);
size_t					ft_strlen(const char *s);
char					*ft_strnew(size_t size);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_itoa(long long int n);
int						ft_minus_zero(double num);
int						ft_printf(char *format, ...);
void					check_b(t_t *t);
int						check_format(t_t *t);
int						check_size_type(t_t *t);
void					type_des(t_t *t);
void					put_t_c(t_t *t, unsigned char a);
void					put_t_s(t_t *t, char *str);
void					put_t_p(t_t *t, uintmax_t adr);
void					put_t_x(t_t *t, long long int num);
void					put_t_o(t_t *t, long long int num);
void					put_t_u(t_t *t);
void					put_t_d(t_t *t);
void					put_t_f(t_t *t, long double num);
void					nan_inf(t_t *t, long double num);
void					put_t_prosent(t_t *t);
char					*ft_itoa_base(uintmax_t num, uintmax_t base);
char					*put_accuracy(t_t *t, char *str);
char					*add_a_d(t_t *t, char *str, int l);
char					*put_width(t_t *t, char *str);
char					*add_w_d(t_t *t, char *str, long long int num);
char					*add_w_f(t_t *t, char *str, int l, long double num);
void					add_str_to_b(t_t *t, char *str);
void					ft_strdel(char **as);
void					*ft_memalloc(size_t size);
void					ft_ftoa(t_t *t, t_float *fl);
void					ft_round_f(t_t *t, t_float *fl);
int						ft_atof(t_float *fl, int i);
char					*add_w_x(t_t *t, char *sn, int flag);

#endif
