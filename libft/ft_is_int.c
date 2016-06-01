/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 18:04:08 by cdeniau           #+#    #+#             */
/*   Updated: 2016/04/10 18:08:04 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_int(char const *str)
{
	char	*tmp;
	int		ret;
	int		neg;

	ret = 0;
	if (str)
	{
		neg = (str[0] == '+' || str[0] == '-') ? 1 : 0;
		tmp = ft_itoa(ft_atoi(str));
		if (ft_strcmp(tmp, str + neg) == 0)
			ret = 1;
	}
	return (ret);
}

