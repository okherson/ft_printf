/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_flags_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:16:23 by okherson          #+#    #+#             */
/*   Updated: 2019/04/18 17:52:58 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	dop(t_t *t, int dop_w, char *s)
{
	while (dop_w > 0)
	{
		if (t->f.o == 1 && ((t->f.accuracy == 0 && t->f.type != '%') ||
		(t->f.type == '%')))
			s[dop_w - 1] = '0';
		else
			s[dop_w - 1] = ' ';
		dop_w--;
	}
}

char		*put_width(t_t *t, char *sn)
{
	char	*s;
	char	*fr;
	int		l;
	int		dop_w;

	fr = NULL;
	l = ft_strlen(sn);
	dop_w = t->f.width - l;
	s = ft_memalloc((t->f.width + 1) * sizeof(char));
	dop(t, dop_w, s);
	fr = sn;
	if (t->f.minus == 1)
		sn = ft_strjoin(sn, s);
	else
		sn = ft_strjoin(s, sn);
	if (fr != NULL)
		ft_strdel(&s);
	return (sn);
}
