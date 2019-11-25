/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:12:45 by okherson          #+#    #+#             */
/*   Updated: 2019/05/06 15:30:00 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		add_str_to_b(t_t *t, char *str)
{
	char	*fr;

	fr = str;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		if ((t->bp) >= 2000)
			check_b(t);
		t->b[t->bp] = *str;
		str++;
		t->bp++;
	}
	if (fr != NULL)
		ft_strdel(&fr);
}
