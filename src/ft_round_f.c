/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:44:07 by okherson          #+#    #+#             */
/*   Updated: 2019/04/25 11:44:13 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_grow_num(char *str, int i)
{
	int		l;
	char	*s;

	l = ft_strlen(str) + 2;
	i = 0;
	s = NULL;
	s = ft_memalloc(l);
	if (*str == '-')
	{
		s[i] = '-';
		i++;
	}
	s[i] = '1';
	i++;
	while (i < l - 1)
	{
		s[i] = '0';
		i++;
	}
	s[i] = '\0';
	ft_strdel(&str);
	return (s);
}

static int	ft_round(char *str, int i)
{
	int		res;

	if (i >= 0 && str[i] >= '0' && str[i] < '9')
	{
		str[i] = str[i] + 1;
		return (0);
	}
	else if (i > 0 && str[i] == '9')
	{
		str[i] = '0';
		res = ft_round(str, i - 1);
	}
	else if (i == 0 && str[i] == '9')
	{
		str[i] = '0';
		return (1);
	}
	else
		return (1);
	return (res);
}

void		ft_round_f2(t_t *t, t_float *fl)
{
	int		n;

	n = 0;
	if (fl->str_sp[t->f.accuracy] > '5')
		n = ft_round(fl->str_sp, t->f.accuracy - 1);
	else if (fl->str_sp[t->f.accuracy] == '5')
	{
		if (ft_atof(fl, t->f.accuracy) == 1)
			n = ft_round(fl->str_sp, t->f.accuracy - 1);
		else if (((fl->str_sp[t->f.accuracy] - '0') % 2) == 1)
			n = ft_round(fl->str_sp, t->f.accuracy - 1);
	}
	fl->str_sp[t->f.accuracy] = '\0';
	if (n == 1)
		n = ft_round(fl->str_fp, fl->len_fp - 1);
	if (n == 1)
		fl->str_fp = ft_grow_num(fl->str_fp, fl->len_fp - 1);
}

void		ft_round_f(t_t *t, t_float *fl)
{
	int		n;

	n = 0;
	if (t->f.accuracy == -2 || t->f.accuracy == -1)
	{
		if (fl->str_sp[0] > '5')
			n = ft_round(fl->str_fp, fl->len_fp - 1);
		else if (fl->str_sp[0] == '5')
		{
			if (ft_atof(fl, 0) == 1)
				n = ft_round(fl->str_fp, fl->len_fp - 1);
			else if ((fl->fp % 2) == 1 || (fl->fp % 2) == -1)
				n = ft_round(fl->str_fp, fl->len_fp - 1);
		}
		ft_strdel(&fl->str_sp);
		if (n == 1)
			fl->str_fp = ft_grow_num(fl->str_fp, fl->len_fp - 1);
	}
	else
		ft_round_f2(t, fl);
}
