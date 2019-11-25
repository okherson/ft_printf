/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 10:51:01 by okherson          #+#    #+#             */
/*   Updated: 2019/04/13 11:37:21 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				ft_bzero(void *s, size_t n)
{
	unsigned char	*set;
	size_t			i;

	set = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		set[i] = '\0';
		i++;
	}
}
