/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:54:55 by okherson          #+#    #+#             */
/*   Updated: 2019/05/06 16:19:19 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	num_skip(t_t *t)
{
	if (t->s[t->sp] == '*')
	{
		if ((t->f.width = (int)va_arg(t->ap, void *)) < 0)
		{
			t->f.width = -t->f.width;
			t->f.minus = 1;
		}
	}
	else if (t->s[t->sp] > '0' && t->s[t->sp] <= '9')
		t->f.width = ft_atoi((char *)(&(t->s[t->sp])));
	else if (t->s[t->sp] == '.')
	{
		t->sp++;
		if (t->s[t->sp] == '*')
			t->f.accuracy = (int)va_arg(t->ap, void *);
		else if (t->s[t->sp] >= '0' && t->s[t->sp] <= '9')
			t->f.accuracy = (ft_atoi((char *)(&(t->s[t->sp]))) == 0) ? -1
			: ft_atoi((char *)(&(t->s[t->sp])));
		else
			t->f.accuracy = -2;
	}
	while ((t->s[t->sp] >= '0' && t->s[t->sp] <= '9') || t->s[t->sp] == '*')
		t->sp++;
	t->sp--;
}

static void	check_flag(t_t *t)
{
	t->f.o = ((t->s[t->sp] == '0' || t->f.o == 1) ? 1 : 0);
	t->f.grill = ((t->s[t->sp] == '#' || t->f.grill == 1) ? 1 : 0);
	t->f.minus = ((t->s[t->sp] == '-' || t->f.minus == 1) ? 1 : 0);
	t->f.plus = ((t->s[t->sp] == '+' || t->f.plus == 1) ? 1 : 0);
	t->f.space = ((t->s[t->sp] == ' ' || t->f.space == 1) ? 1 : 0);
	if (t->f.minus == 1)
		t->f.o = 0;
}

int			check_format(t_t *t)
{
	while (t->s[t->sp++])
	{
		if (t->s[t->sp] == 32 || t->s[t->sp] == 35 || t->s[t->sp] == 43 ||
		t->s[t->sp] == 45 || t->s[t->sp] == 48)
			check_flag(t);
		else if ((t->s[t->sp] > '0' && t->s[t->sp] <= '9' && t->f.width == 0) ||
		t->s[t->sp] == '*')
			num_skip(t);
		else if (t->s[t->sp] == '.' && t->f.accuracy == 0)
			num_skip(t);
		else if (check_size_type(t) == 1)
			return (1);
		if (t->s[t->sp] == 'p' || t->s[t->sp] == 'd' || t->s[t->sp] == 'i'
	|| t->s[t->sp] == 'o' || t->s[t->sp] == 'u' || t->s[t->sp] == 'x' ||
	t->s[t->sp] == 'X' || t->s[t->sp] == 'c' || t->s[t->sp] == 's' ||
	t->s[t->sp] == 'f' || t->s[t->sp] == 'h' || t->s[t->sp] == 'z' ||
	t->s[t->sp] == 'l' || t->s[t->sp] == 'L' || t->s[t->sp] == '%' ||
	t->s[t->sp] == 'U' || t->s[t->sp] == 'F' || t->s[t->sp] == 'D')
			break ;
	}
	return (0);
}
