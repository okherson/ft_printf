/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_t_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:25:42 by okherson          #+#    #+#             */
/*   Updated: 2019/05/06 15:39:14 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*add_pref(t_t *t, char *sn, long double num)
{
	char	*fr;

	if (t->f.space == 1)
		fr = " ";
	if (t->f.plus == 1)
		fr = "+";
	if (num < 0)
		fr = "-";
	if (*sn == '-')
		fr = "";
	sn = ft_strjoin(fr, sn);
	return (sn);
}

static void	f_together(t_float *fl)
{
	char	*fr;

	fr = fl->str_fp;
	fl->str_fp = ft_strjoin(fl->str_fp, ".");
	ft_strdel(&fr);
	fr = fl->str_fp;
	fl->str_fp = ft_strjoin(fl->str_fp, fl->str_sp);
	ft_strdel(&fr);
	ft_strdel(&fl->str_sp);
}

void		put_t_f3(t_t *t, t_float *fl, long double num, char *fr)
{
	int		l;

	l = 0;
	if (t->f.width > (int)ft_strlen(fl->str_fp))
	{
		fr = fl->str_fp;
		fl->str_fp = add_w_f(t, fl->str_fp, (int)ft_strlen(fl->str_fp), num);
		ft_strdel(&fr);
	}
	if (((*fl->str_fp != ' ' && *fl->str_fp != '-' && *fl->str_fp != '+' &&
	(t->f.plus == 1 || t->f.space == 1 || num < 0)) || (t->f.space == 1 &&
	*fl->str_fp == ' ')))
	{
		fr = fl->str_fp;
		fl->str_fp = add_pref(t, fl->str_fp, num);
		ft_strdel(&fr);
	}
	if (t->f.type == 'F')
		while (fl->str_fp[l] != '\0')
		{
			if (fl->str_fp[l] >= 'a' && fl->str_fp[l] <= 'z')
				fl->str_fp[l] = fl->str_fp[l] - 32;
			l++;
		}
	add_str_to_b(t, fl->str_fp);
}

void		put_t_f2(t_t *t, t_float *fl, long double num, char *fr)
{
	int		l;

	if (t->f.accuracy > 0)
		f_together(fl);
	if (t->f.grill == 1 && t->f.accuracy < 1)
	{
		fr = fl->str_fp;
		fl->str_fp = ft_strjoin(fl->str_fp, ".");
		ft_strdel(&fr);
	}
	l = ft_strlen(fl->str_fp);
	if (num == num && t->f.o != 1 && (t->f.plus == 1 || *fl->str_fp == '-')
	&& (t->f.space == 1 || t->f.width > l || t->f.accuracy > l))
	{
		fr = fl->str_fp;
		fl->str_fp = add_pref(t, fl->str_fp, num);
		ft_strdel(&fr);
	}
	put_t_f3(t, fl, num, fr);
}

void		put_t_f(t_t *t, long double num)
{
	t_float	fl;
	char	*fr;

	fr = NULL;
	ft_bzero((void *)&fl, sizeof(t_float));
	if (num != num || num == 0.0 / 0.0 || num == 3.0 / 0.0 || num == -3.0 / 0.0)
		nan_inf(t, num);
	else
	{
		t->f.accuracy = t->f.accuracy == 0 ? 6 : t->f.accuracy;
		fl.fp = (long int)num;
		fl.sp = num > 0 ? num - (long double)fl.fp : -num + (long double)fl.fp;
		(num == 0 && ft_minus_zero(num) == 1) ? (fl.str_fp = ft_strdup("-0"))
		: (fl.str_fp = ft_itoa(fl.fp));
		fl.str_sp = (t->f.accuracy > 0) ? ft_memalloc(t->f.accuracy + 2)
				: ft_memalloc(3);
		fl.len_fp = ft_strlen(fl.str_fp);
		ft_ftoa(t, &fl);
		ft_round_f(t, &fl);
		put_t_f2(t, &fl, num, fr);
	}
}
