/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_t_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:43:31 by okherson          #+#    #+#             */
/*   Updated: 2019/05/06 14:42:51 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			ad_width(t_t *t, unsigned char a)
{
	unsigned char	a2;

	a2 = (unsigned char)a;
	if (t->f.minus == 1)
		t->b[t->bp++] = a2;
	while (--t->f.width > 0)
	{
		if ((t->bp) >= 2000)
			check_b(t);
		if (t->f.o == 1)
			t->b[t->bp++] = '0';
		else
			t->b[t->bp++] = ' ';
	}
	if (t->f.minus == 0)
		t->b[t->bp++] = a2;
}

void				put_t_c(t_t *t, unsigned char a)
{
	unsigned char	a2;

	a2 = (unsigned char)a;
	if (t->f.width != -1 && t->f.width != 0 && t->f.width != 1)
		ad_width(t, a);
	else
	{
		t->b[t->bp] = a2;
		t->bp++;
	}
}
