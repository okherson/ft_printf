/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nan_inf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:38:07 by okherson          #+#    #+#             */
/*   Updated: 2019/05/10 12:38:15 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	cont(t_t *t, char *sn)
{
	int		l;

	l = 0;
	if (t->f.type == 'F')
		while (sn[l] != '\0')
		{
			if (sn[l] >= 'a' && sn[l] <= 'z')
				sn[l] = sn[l] - 32;
			l++;
		}
	add_str_to_b(t, sn);
}

void		nan_inf(t_t *t, long double num)
{
	char	*sn;
	int		l;
	char	*fr;

	if (num != num || num == 0.0 / 0.0)
		sn = ft_strdup("nan");
	else if (num == 3.0 / 0.0 || num == -3.0 / 0.0)
	{
		if (num == 3.0 / 0.0 && t->f.space == 1 && t->f.plus != 1)
			sn = ft_strdup(" inf");
		else if (num == -3.0 / 0.0)
			sn = ft_strdup("-inf");
		else if (num == 3.0 / 0.0 && t->f.plus == 1)
			sn = ft_strdup("+inf");
		else
			sn = ft_strdup("inf");
	}
	l = (int)ft_strlen(sn);
	if (t->f.width > l)
	{
		fr = sn;
		sn = add_w_f(t, sn, l, num);
		ft_strdel(&fr);
	}
	cont(t, sn);
}
