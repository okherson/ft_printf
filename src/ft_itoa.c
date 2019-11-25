/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:42:35 by okherson          #+#    #+#             */
/*   Updated: 2019/04/16 17:55:39 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int				ft_len(long long int n, unsigned long int pn)
{
	int					i;

	i = 1;
	if (n < 0)
		i++;
	while (pn > 9)
	{
		i++;
		pn = pn / 10;
	}
	return (i);
}

static void				ft_str(char **str, unsigned long int pn, int ln)
{
	while (ln >= 0)
	{
		if ((*str)[ln] == '-')
			break ;
		else
		{
			(*str)[ln] = pn % 10 + '0';
			pn = pn / 10;
		}
		ln--;
	}
}

char					*ft_itoa(long long int n)
{
	char				*str;
	int					ln;
	unsigned long int	pn;

	if (n < 0)
		pn = -n;
	else
		pn = n;
	ln = ft_len(n, pn);
	str = (char *)ft_memalloc((ln + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, ln + 1);
	if (n < 0)
		str[0] = '-';
	ft_str(&str, pn, ln - 1);
	return (str);
}
