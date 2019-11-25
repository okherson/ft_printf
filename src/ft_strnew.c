/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:59:04 by okherson          #+#    #+#             */
/*   Updated: 2019/04/13 11:36:55 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char				*ft_strnew(size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)malloc((size + 1) * sizeof(unsigned char));
	if (str == NULL)
		return (NULL);
	else
		ft_bzero(str, size + 1);
	return ((char *)str);
}
