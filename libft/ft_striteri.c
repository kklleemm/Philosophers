/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:59:15 by cdeniau           #+#    #+#             */
/*   Updated: 2014/11/19 10:52:00 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	int		j;

	if (!s)
		return ;
	j = strlen(s);
	i = 0;
	while (i < j)
	{
		(*f)(i, s);
		i++;
		s++;
	}
}
