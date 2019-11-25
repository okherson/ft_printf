/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_t_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:25:24 by okherson          #+#    #+#             */
/*   Updated: 2019/04/18 20:07:41 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		put_u(t_t *t, unsigned long long int num)
{
	char		*fr;
	char		*sn;

	sn = NULL;
	sn = ft_itoa_base(num, 10);
	if (t->f.accuracy < 0 && num == 0)
	{
		fr = sn;
		sn = ft_strdup("");
		ft_strdel(&fr);
	}
	else if (t->f.accuracy > (int)ft_strlen(sn))
	{
		fr = sn;
		sn = put_accuracy(t, sn);
		ft_strdel(&fr);
	}
	if (t->f.width > (int)ft_strlen(sn))
	{
		fr = sn;
		sn = put_width(t, sn);
		ft_strdel(&fr);
	}
	add_str_to_b(t, sn);
}

void			put_t_u(t_t *t)
{
	if (t->f.size == -1)
		put_u(t, ((unsigned short int)va_arg(t->ap, void *)));
	else if (t->f.size == -2)
		put_u(t, ((unsigned char)va_arg(t->ap, void *)));
	else if (t->f.size == 1)
		put_u(t, (unsigned long int)va_arg(t->ap, void *));
	else if (t->f.size == 2)
		put_u(t, ((unsigned long long int)va_arg(t->ap, void *)));
	else if (t->f.size == 3)
		put_u(t, ((unsigned long int)va_arg(t->ap, void *)));
	else if (t->f.size == 4)
		put_u(t, ((uintmax_t)va_arg(t->ap, void *)));
	else
		put_u(t, ((unsigned int)va_arg(t->ap, void *)));
}
