/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:27:20 by okherson          #+#    #+#             */
/*   Updated: 2019/04/18 12:46:43 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *str;

	str = (unsigned char *)malloc(size * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return ((void *)str);
}
