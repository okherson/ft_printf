/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:11:20 by okherson          #+#    #+#             */
/*   Updated: 2019/05/02 11:11:24 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_minus_zero(double num)
{
	long long	*tmp;
	long long	bit_move;
	long long	j;

	tmp = (long long *)(&num);
	bit_move = *tmp;
	j = bit_move >> 63;
	if (j < 0)
		return (1);
	return (0);
}
