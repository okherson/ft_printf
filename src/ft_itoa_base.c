/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:21:41 by okherson          #+#    #+#             */
/*   Updated: 2019/04/13 14:10:18 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		get_str_num(char **str_n, uintmax_t num, uintmax_t base, int l)
{
	int			rest;

	while (--l >= 0)
	{
		rest = num % base;
		num /= base;
		if (rest >= 0 && rest < 10)
			(*str_n)[l] = (char)(rest + '0');
		else
			(*str_n)[l] = (char)(rest - 10 + 'a');
	}
}

static int		num_len(uintmax_t num, uintmax_t base)
{
	int			l;

	l = 0;
	while (num)
	{
		num = num / base;
		l++;
	}
	return (l);
}

char			*ft_itoa_base(uintmax_t num, uintmax_t base)
{
	int			l;
	char		*str_n;

	if (num == 0)
	{
		if (!(str_n = ft_strnew(1)))
			return (NULL);
		*str_n = '0';
		return (str_n);
	}
	l = num_len(num, base);
	str_n = ft_memalloc((l + 1) * sizeof(char));
	str_n[l] = '\0';
	get_str_num(&str_n, num, base, l);
	return (str_n);
}
