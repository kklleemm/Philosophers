/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 16:09:49 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/06 16:42:48 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	ft_check_angle(float angle)
{
	while (angle > 360 || angle < -360)
	{
		if (angle > 360)
			angle -= 360;
		else
			angle += 360;
	}
	if (angle > 180)
		angle -= 360;
	else if (angle < -180)
		angle += 360;
	return (angle);
}

float			ft_sin(float angle)
{
	float	ret;
	int		n;

	angle = ft_check_angle(angle);
	n = 0;
	angle *= 3.14;
	angle /= 180;
	ret = angle;
	while (++n < 5)
		ret += ft_power(-1, n) * ((ft_power(angle, n + n + 1), \
					ft_fact(n + n + 1)));
	if (ret > 1)
		return (1);
	if (ret < -1)
		return (-1);
	return (ret);
}
