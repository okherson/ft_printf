/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_t_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:33:19 by okherson          #+#    #+#             */
/*   Updated: 2019/04/19 12:39:46 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		put_t_p_2(t_t *t, char *sn, char *fr, char *pref)
{
	if (t->f.o == 1)
	{
		fr = sn;
		sn = ft_strjoin(pref, sn);
		ft_strdel(&fr);
	}
	add_str_to_b(t, sn);
}

void		put_t_p(t_t *t, uintmax_t adr)
{
	char	*sn;
	char	*pref;
	char	*fr;

	sn = ft_itoa_base(adr, (uintmax_t)16);
	pref = "0x";
	if (t->f.o != 1)
	{
		fr = sn;
		sn = ft_strjoin(pref, sn);
		ft_strdel(&fr);
	}
	else
		t->f.width = t->f.width - 2;
	if (t->f.width > (int)ft_strlen(sn))
	{
		fr = sn;
		sn = put_width(t, sn);
		ft_strdel(&fr);
	}
	put_t_p_2(t, sn, fr, pref);
}
