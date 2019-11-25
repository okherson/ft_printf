/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_a_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:15:46 by okherson          #+#    #+#             */
/*   Updated: 2019/05/06 13:13:46 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*add_a_d(t_t *t, char *str, int l)
{
	char	*pref;
	int		len;

	pref = NULL;
	len = t->f.accuracy - l;
	if (len == 0 && (*str == '-' || *str == '+'))
	{
		pref = (*str == '-') ? "-" : "+";
		*str = '0';
		str = ft_strjoin(pref, str);
		return (str);
	}
	pref = ft_memalloc((len + 1) * sizeof(char));
	while (--len >= 0)
		pref[len] = '0';
	if (*str == '-' || *str == '+')
		*str = '0';
	if (*str == '-' && (t->f.o != 1 && t->f.accuracy == 0))
		pref[0] = '-';
	else if (t->f.plus == 1 && (t->f.o != 1 && t->f.accuracy == 0))
		pref[0] = '+';
	str = ft_strjoin(pref, str);
	ft_strdel(&pref);
	return (str);
}
