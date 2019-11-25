/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:12:04 by okherson          #+#    #+#             */
/*   Updated: 2019/04/18 17:38:28 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_strdup(char *s1)
{
	char	*dup;
	int		i;

	i = ft_strlen(s1);
	dup = (char*)malloc((i + 1) * sizeof(char));
	i = 0;
	if (dup == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
