/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_w_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:53:31 by okherson          #+#    #+#             */
/*   Updated: 2019/05/06 13:27:49 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	add_o_(char **pref, t_t *t, char *sn, long long int num)
{
	int		len;

	len = (t->f.width - (int)ft_strlen(sn));
	len = (t->f.minus == 1 && t->f.plus == 1 && *sn != '+' && *sn != '-')
	? len - 1 : len;
	len = (t->f.space && t->f.plus == 0 && *sn != '-' && num >= 0) ? len - 1
	: len;
	*pref = ft_memalloc((len + 1));
	len--;
	while (len >= 0)
	{
		if (t->f.o == 1 && t->f.accuracy == 0)
			(*pref)[len] = '0';
		else
			(*pref)[len] = ' ';
		len--;
	}
	if ((num < 0 && *sn != '-') || (*sn == '-' && (t->f.o == 1 &&
	t->f.accuracy == 0)))
		*pref[0] = '-';
	else if (t->f.plus == 1 && (t->f.o == 1 && t->f.accuracy == 0))
		*pref[0] = '+';
}

char		*add_w_d(t_t *t, char *sn, long long int num)
{
	char	*pref;

	pref = NULL;
	add_o_(&pref, t, sn, num);
	if (t->f.o == 1 && t->f.accuracy == 0 && (*sn == '+' || *sn == '-'))
		*sn = '0';
	if (t->f.minus == 1 && *pref != '-')
		sn = ft_strjoin(sn, pref);
	else
		sn = ft_strjoin(pref, sn);
	ft_strdel(&pref);
	return (sn);
}
