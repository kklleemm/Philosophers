/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 13:39:05 by cdeniau           #+#    #+#             */
/*   Updated: 2014/11/14 14:07:57 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * size);
	if (str)
	{
		i = 0;
		while (i < (int)size)
			str[i++] = '\0';
		return (str);
	}
	else
		return (NULL);
}
