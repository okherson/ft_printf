/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_des.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:07:08 by okherson          #+#    #+#             */
/*   Updated: 2019/05/06 15:38:02 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	type_des2(t_t *t)
{
	if (t->f.type == 'p')
		put_t_p(t, ((uintmax_t)va_arg(t->ap, void *)));
	else if (t->f.type == 'f' || t->f.type == 'F')
	{
		if (t->f.size == 3)
			put_t_f(t, va_arg(t->ap, long double));
		else
			put_t_f(t, va_arg(t->ap, double));
	}
}

static void	type_des1(t_t *t)
{
	if (t->f.type == 'o')
	{
		if (t->f.size == -1)
			put_t_o(t, ((unsigned short int)va_arg(t->ap, void *)));
		else if (t->f.size == -2)
			put_t_o(t, ((unsigned char)va_arg(t->ap, void *)));
		else if (t->f.size == 1)
			put_t_o(t, (unsigned long int)va_arg(t->ap, void *));
		else if (t->f.size == 2)
			put_t_o(t, ((unsigned long long int)va_arg(t->ap, void *)));
		else if (t->f.size == 3)
			put_t_o(t, ((long long int)va_arg(t->ap, void *)));
		else if (t->f.size == 4)
			put_t_o(t, ((intmax_t)va_arg(t->ap, void *)));
		else
			put_t_o(t, ((unsigned int)va_arg(t->ap, void *)));
	}
	else if (t->f.type == 'u')
		put_t_u(t);
	else if (t->f.type == 'd' || t->f.type == 'D' || t->f.type == 'i')
		put_t_d(t);
	else if (t->f.type == '%')
		put_t_prosent(t);
	else
		type_des2(t);
}

void		type_des(t_t *t)
{
	if (t->f.type == 'c')
		put_t_c(t, (int)(va_arg(t->ap, void *)));
	else if (t->f.type == 's')
		put_t_s(t, ((char *)va_arg(t->ap, void *)));
	else if (t->f.type == 'x' || t->f.type == 'X')
	{
		if (t->f.size == -1)
			put_t_x(t, ((unsigned short int)va_arg(t->ap, void *)));
		else if (t->f.size == -2)
			put_t_x(t, ((unsigned char)va_arg(t->ap, void *)));
		else if (t->f.size == 1)
			put_t_x(t, (unsigned long int)va_arg(t->ap, void *));
		else if (t->f.size == 2)
			put_t_x(t, ((unsigned long long int)va_arg(t->ap, void *)));
		else if (t->f.size == 3)
			put_t_x(t, ((long long int)va_arg(t->ap, void *)));
		else if (t->f.size == 4)
			put_t_x(t, ((uintmax_t)va_arg(t->ap, void *)));
		else
			put_t_x(t, ((unsigned int)va_arg(t->ap, void *)));
	}
	else
		type_des1(t);
}
