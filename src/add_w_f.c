/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_w_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:45:56 by okherson          #+#    #+#             */
/*   Updated: 2019/04/23 12:45:59 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	add_o_(char **pref, int dop_w, t_t *t, long double num)
{
	while (dop_w >= 0)
	{
		if (t->f.o == 1 && (num == num && num != 3.0 / 0.0
		&& num != -3.0 / 0.0))
			(*pref)[dop_w] = '0';
		else
			(*pref)[dop_w] = ' ';
		dop_w--;
	}
}

static void	add_w_f_2(t_t *t, char *s, long double num)
{
	if (num < 0 && num != -3.0 / 0.0 && s[1] >= '0' && s[1] <= '9')
		s[0] = '-';
	else if (num > 0 && num != 3.0 / 0.0 && t->f.plus == 1 && s[1] >= '0'
	&& s[1] <= '9')
		s[0] = '+';
}

char		*add_w_f(t_t *t, char *s, int l, long double num)
{
	char	*pref;
	int		len;

	pref = NULL;
	len = (t->f.width - l);
	len = (t->f.space == 1 && *s != '-' && num == 0.0 / 0.0) ? len - 1 : len;
	pref = ft_memalloc((len + 1) * sizeof(char));
	add_o_(&pref, len - 1, t, num);
	if (*s == '-' && (num == num && num != 3.0 / 0.0 && num != -3.0 / 0.0))
		s[0] = '-';
	else if (*s == '+' && (num == num && num != 3.0 / 0.0 && num != -3.0 / 0.0))
		s[0] = '+';
	if (t->f.o == 1 && (*s == '+' || *s == '-') && num != -3.0 / 0.0 &&
	num != 3.0 / 0.0)
		*s = '0';
	if (t->f.minus == 1)
		s = ft_strjoin(s, pref);
	else
		s = ft_strjoin(pref, s);
	add_w_f_2(t, s, num);
	ft_strdel(&pref);
	return (s);
}
