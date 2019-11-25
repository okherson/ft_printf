/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_t_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:05:01 by okherson          #+#    #+#             */
/*   Updated: 2019/05/06 13:25:49 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*add_pref(t_t *t, char *sn, long long int num)
{
	char	*fr;

	if (t->f.space == 1)
	{
		fr = " ";
		t->f.space++;
	}
	if (t->f.plus == 1 && *sn != '-' && *sn != '+')
		fr = "+";
	if (num < 0 && *sn >= '0' && *sn <= '9')
		fr = "-";
	if (*sn == '-')
		fr = "";
	sn = ft_strjoin(fr, sn);
	return (sn);
}

static void	put_d_3(t_t *t, long long int num, char *sn, char *fr)
{
	if (((*sn != ' ' && *sn != '-' && *sn != '+' && (t->f.plus == 1 ||
	t->f.space == 1 || num < 0)) || (t->f.space == 1 && *sn == ' ')) ||
		(t->f.space == 1))
	{
		fr = sn;
		sn = add_pref(t, sn, num);
		ft_strdel(&fr);
	}
	if (num < 0 && sn[0] != '-' && sn[1] >= '0' && sn[1] <= '9')
		sn[0] = '-';
	add_str_to_b(t, sn);
}

static void	put_d_2(t_t *t, long long int num, char *sn, char *fr)
{
	int		l;

	l = ft_strlen(sn);
	if (t->f.accuracy >= l)
	{
		fr = sn;
		sn = add_a_d(t, sn, l);
		ft_strdel(&fr);
	}
	if (t->f.plus == 1 && (t->f.o == 0 || (t->f.o == 1 && t->f.accuracy > -3))
	&& *sn != '+')
	{
		fr = sn;
		sn = add_pref(t, sn, num);
		ft_strdel(&fr);
	}
	l = ft_strlen(sn);
	if (t->f.width > l)
	{
		fr = sn;
		sn = add_w_d(t, sn, num);
		ft_strdel(&fr);
	}
	put_d_3(t, num, sn, fr);
}

static void	put_d(t_t *t, long long int num)
{
	char	*fr;
	char	*sn;
	int		l;

	sn = NULL;
	sn = ft_itoa(num);
	if (num == 0 && t->f.accuracy < 0)
	{
		fr = sn;
		sn = ft_strdup("");
		ft_strdel(&fr);
	}
	l = ft_strlen(sn);
	if (t->f.o != 1 && (t->f.plus == 1 || *sn == '-') && (t->f.space == 1 ||
	t->f.width > l || t->f.accuracy > l))
	{
		fr = sn;
		sn = add_pref(t, sn, num);
		ft_strdel(&fr);
	}
	put_d_2(t, num, sn, fr);
}

void		put_t_d(t_t *t)
{
	if (t->f.size == -1 && t->f.type != 'D')
		put_d(t, ((short int)va_arg(t->ap, void *)));
	else if (t->f.size == -2 && t->f.type != 'D')
		put_d(t, ((char)va_arg(t->ap, void *)));
	else if (t->f.size == 1 || t->f.type == 'D')
		put_d(t, (long int)va_arg(t->ap, void *));
	else if (t->f.size == 2)
		put_d(t, ((long long int)va_arg(t->ap, void *)));
	else if (t->f.size == 3)
		put_d(t, ((long int)va_arg(t->ap, void *)));
	else if (t->f.size == 4)
		put_d(t, ((intmax_t)va_arg(t->ap, void *)));
	else if (t->f.size == 5)
		put_d(t, ((size_t)va_arg(t->ap, void *)));
	else if (t->f.size == 5)
		put_d(t, ((size_t)va_arg(t->ap, void *)));
	else
		put_d(t, ((int)va_arg(t->ap, void *)));
}
