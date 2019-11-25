/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:17:24 by okherson          #+#    #+#             */
/*   Updated: 2019/04/18 17:38:18 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		i;

	if (s1 && !s2)
		return (ft_strdup((char *)s1));
	else if (!s1 && s2)
		return (ft_strdup((char *)s2));
	else if (!s1 && !s2)
		return (NULL);
	i = (ft_strlen(s1) + ft_strlen(s2));
	concat = (char *)malloc(i + 1);
	if (!concat)
		return (NULL);
	ft_strcpy(concat, s1);
	ft_strcat(concat, s2);
	return (concat);
}
