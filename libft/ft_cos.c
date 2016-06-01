/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 16:01:01 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/06 16:34:17 by cdeniau          ###   ########.fr       */
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

float			ft_cos(float angle)
{
	float		ret;
	int			n;

	angle = ft_check_angle(angle);
	angle *= 3.14159;
	angle /= 180;
	n = 0;
	ret = 1;
	while (++n < 5)
		ret += ft_power(-1, n) * ((ft_power(angle, n + n) / ft_fact(n + n)));
	if (ret > 1)
		return (EXIT_SUCCESS);
	if (ret < -1)
		return (EXIT_FAILURE);
	return (ret);
}
