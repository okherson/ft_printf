/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_t_prosent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:45:43 by okherson          #+#    #+#             */
/*   Updated: 2019/04/19 14:14:45 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		put_t_prosent(t_t *t)
{
	char	*str;
	char	*fr;

	fr = NULL;
	str = ft_strdup("%");
	if (t->f.width > (int)ft_strlen(str))
	{
		fr = str;
		str = put_width(t, str);
		ft_strdel(&fr);
	}
	add_str_to_b(t, str);
}
