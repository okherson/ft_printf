/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:11:55 by okherson          #+#    #+#             */
/*   Updated: 2019/05/06 14:57:50 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	check_type(t_t *t)
{
	t->f.type = (t->s[t->sp] == 'd' || t->s[t->sp] == 'i') ? 'd' : t->f.type;
	t->f.type = (t->s[t->sp] == 'o') ? 'o' : t->f.type;
	t->f.type = (t->s[t->sp] == 'u') ? 'u' : t->f.type;
	t->f.type = (t->s[t->sp] == 'x') ? 'x' : t->f.type;
	t->f.type = (t->s[t->sp] == 'X') ? 'X' : t->f.type;
	t->f.type = (t->s[t->sp] == 'c') ? 'c' : t->f.type;
	t->f.type = (t->s[t->sp] == 'p') ? 'p' : t->f.type;
	t->f.type = (t->s[t->sp] == 'f') ? 'f' : t->f.type;
	t->f.type = (t->s[t->sp] == 'F') ? 'F' : t->f.type;
	t->f.type = (t->s[t->sp] == '%') ? '%' : t->f.type;
	t->f.type = (t->s[t->sp] == 's') ? 's' : t->f.type;
	t->f.type = (t->s[t->sp] == 'D') ? 'D' : t->f.type;
}

static void	check_h(t_t *t)
{
	t->sp++;
	if (t->s[t->sp] == 'h')
	{
		t->f.size = -2;
		t->sp++;
	}
	else
		t->f.size = -1;
}

static void	check_l(t_t *t)
{
	t->sp++;
	if (t->s[t->sp] == 'l')
	{
		t->f.size = 2;
		t->sp++;
	}
	else
		t->f.size = 1;
}

static void	check_ll(t_t *t)
{
	if (t->s[t->sp] == 'j')
	{
		t->f.size = 4;
		t->sp++;
	}
	else if (t->s[t->sp] == 'L')
	{
		t->f.size = 3;
		t->sp++;
	}
	else if (t->s[t->sp] == 'z')
	{
		t->f.size = 5;
		t->sp++;
	}
	else
		t->f.undef = 1;
}

int			check_size_type(t_t *t)
{
	if (t->s[t->sp] == 'h')
		check_h(t);
	else if (t->s[t->sp] == 'l')
		check_l(t);
	else if (t->s[t->sp] == 'L' || t->s[t->sp] == 'j' || t->s[t->sp] == 'z')
		check_ll(t);
	check_type(t);
	return (0);
}
