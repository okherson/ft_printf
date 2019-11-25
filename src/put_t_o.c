/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_t_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:56:43 by okherson          #+#    #+#             */
/*   Updated: 2019/04/19 11:53:51 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*add_pref(char *sn)
{
	int			len;
	char		*fr;
	int			n;
	int			m;

	n = 1;
	m = 0;
	len = ft_strlen(sn);
	fr = malloc((len + 2) * sizeof(char));
	fr[0] = '0';
	while (sn[m])
	{
		fr[n] = sn[m];
		n++;
		m++;
	}
	fr[n] = '\0';
	return (fr);
}

static void		put_t_o_3(t_t *t, char *sn, int flag_pref, long long int num)
{
	int		l;
	char	*fr;

	l = 0;
	if (t->f.grill == 1 && num != 0 && t->f.o == 1 && flag_pref != 1
	&& *sn != ' ')
	{
		fr = sn;
		sn = add_pref(sn);
		ft_strdel(&fr);
	}
	if (t->f.type == 'X')
		while (sn[l])
		{
			if ((sn[l] >= 'a' && sn[l] <= 'f') || sn[l] == 'x')
				sn[l] = sn[l] - 32;
			l++;
		}
	add_str_to_b(t, sn);
}

static void		put_t_o_2(t_t *t, long long int num, char *sn, char *fr)
{
	int		flag_pref;

	flag_pref = 0;
	if (t->f.accuracy > (int)ft_strlen(sn))
	{
		fr = sn;
		sn = put_accuracy(t, sn);
		ft_strdel(&fr);
	}
	else if (t->f.grill == 1 && num != 0 && (t->f.o != 1 || t->f.accuracy != 0))
	{
		fr = sn;
		sn = add_pref(sn);
		ft_strdel(&fr);
		flag_pref = 1;
	}
	if (t->f.width > (int)ft_strlen(sn))
	{
		fr = sn;
		sn = put_width(t, sn);
		ft_strdel(&fr);
	}
	put_t_o_3(t, sn, flag_pref, num);
}

void			put_t_o(t_t *t, long long int num)
{
	char		*fr;
	char		*sn;

	fr = NULL;
	sn = ft_itoa_base(num, 8);
	if (t->f.accuracy < 0 && num == 0 && t->f.width == 0 && t->f.grill != 1)
	{
		fr = sn;
		sn = ft_strdup("");
		ft_strdel(&fr);
	}
	put_t_o_2(t, num, sn, fr);
}
