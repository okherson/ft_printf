/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_atof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:41:31 by okherson          #+#    #+#             */
/*   Updated: 2019/04/25 11:41:38 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				ft_ftoa(t_t *t, t_float *fl)
{
	int				p;
	long int		fp;
	int				i;
	long long int	pp;
	long double		num;

	num = fl->sp;
	p = t->f.accuracy < 0 ? 1 : t->f.accuracy;
	i = 0;
	while (p >= 0)
	{
		fp = (long int)num;
		num = (num - fp) * 10;
		pp = (long long int)num % 10;
		if (pp < 0)
			fl->str_sp[i] = '0';
		else
			fl->str_sp[i] = '0' + pp;
		i++;
		p--;
	}
	fl->str_sp[i] = '\0';
}

int					ft_atof(t_float *fl, int i)
{
	long double		compare;
	int				n;
	unsigned int	point;

	point = 10;
	compare = 0.0;
	n = 0;
	while (n <= i && fl->str_sp[n])
	{
		compare = compare + ((long double)(fl->str_sp[n] - '0') / point);
		point *= 10;
		n++;
	}
	if (fl->sp > compare)
		return (1);
	else
		return (0);
}
