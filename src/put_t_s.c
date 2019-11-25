/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_t_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:40:07 by okherson          #+#    #+#             */
/*   Updated: 2019/04/19 12:38:04 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		put_t_s(t_t *t, char *str)
{
	char	*fr;
	char	*clean;

	fr = NULL;
	if (str == NULL)
		str = "(null)";
	fr = ft_strdup(str);
	if ((t->f.accuracy < (int)ft_strlen(str) && t->f.accuracy > -3 &&
	t->f.accuracy != 0) && *str != '\0')
	{
		clean = fr;
		fr = put_accuracy(t, fr);
		ft_strdel(&clean);
	}
	if (t->f.width > (int)ft_strlen(fr))
	{
		clean = fr;
		fr = put_width(t, fr);
		ft_strdel(&clean);
	}
	add_str_to_b(t, fr);
}
