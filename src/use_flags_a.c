/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_flags_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:06:17 by okherson          #+#    #+#             */
/*   Updated: 2019/05/06 16:45:53 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	put_accuracy_min(t_t *t, char *str, char **fr, int l)
{
	int		n;
	int		a;

	a = *str == '-' ? 1 : 0;
	n = 0;
	if (*str == '-')
		(*fr)[n] = '-';
	else
		*fr[n] = 0;
	while (n < t->f.accuracy - l)
		(*fr)[n++] = '0';
	while (n < t->f.accuracy)
		(*fr)[n++] = str[a++];
}

static void	write_fr(t_t *t, char *str, char **fr, int l)
{
	int		n;
	int		ls;

	n = -1;
	ls = 0;
	if (t->f.type == 's')
	{
		while (++n < t->f.accuracy - l - 1)
			(*fr)[n] = ' ';
	}
	else
		while (n++ < t->f.accuracy - l - 1)
			(*fr)[n] = '0';
	while (n < t->f.accuracy)
	{
		(*fr)[n] = str[ls];
		n++;
		ls++;
	}
}

static void	write_minus_s(t_t *t, char *str, char **fr)
{
	int		n;
	int		ls;

	n = 0;
	ls = 0;
	while (str[ls] && ls < t->f.accuracy)
	{
		(*fr)[n] = str[ls];
		n++;
		ls++;
	}
	while (n++ < t->f.accuracy - 1)
		(*fr)[n] = ' ';
}

char		*put_accuracy(t_t *t, char *str)
{
	char	*fr;
	int		len_str;

	fr = NULL;
	len_str = ft_strlen(str);
	if (t->f.accuracy < 0 && t->f.type != 's')
		return (ft_strdup(str));
	if (*str == '-')
		t->f.accuracy++;
	if (t->f.type == 's' && t->f.accuracy < len_str)
	{
		t->f.accuracy = (t->f.accuracy < 0) ? 0 : t->f.accuracy;
		str[t->f.accuracy] = '\0';
		fr = ft_strdup(str);
		return (fr);
	}
	fr = (char*)ft_memalloc((t->f.accuracy + 1) * (sizeof(char)));
	if (*str == '-' || t->f.plus == 1)
		put_accuracy_min(t, str, &fr, len_str);
	else if (t->f.type == 's' && t->f.minus == 1)
		write_minus_s(t, str, &fr);
	else
		write_fr(t, str, &fr, len_str);
	return (fr);
}
