/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:38:30 by okherson          #+#    #+#             */
/*   Updated: 2019/05/06 16:21:02 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_printf(char *form, ...)
{
	t_t		t;
	int		y;

	ft_bzero((void *)&t, sizeof(t_t));
	t.s = form;
	va_start(t.ap, form);
	while (t.s[t.sp])
	{
		if (t.bp >= 2000)
			check_b(&t);
		ft_bzero((void *)&t.f, sizeof(t_f));
		if (t.s[t.sp] != '%')
			t.b[t.bp++] = t.s[t.sp];
		else if (t.s[t.sp] == '%')
		{
			y = (int)check_format(&t);
			type_des(&t);
		}
		t.sp++;
	}
	va_end(t.ap);
	write(1, &(t.b), t.bp);
	t.tl += t.bp;
	return (t.tl);
}
