/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:06:14 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/04 16:19:07 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

float		set_x(int id)
{
	if (id == 0)
		return (.2);
	if (id == 1)
		return (.6);
	if (id == 2)
		return (.3);
	if (id == 3)
		return (0);
	if (id == 4)
		return (-0.3);
	if (id == 5)
		return (-0.6);
	if (id == 6)
		return (-0.2);
	return (0);
}

float		set_y(int id)
{
	if (id == 0)
		return (0.3);
	if (id == 1)
		return (0.1);
	if (id == 2)
		return (-0.3);
	if (id == 3)
		return (-0.5);
	if (id == 4)
		return (-0.3);
	if (id == 5)
		return (0.1);
	if (id == 6)
		return (0.3);
	return (0);
}

char		*get_name(int id)
{
	if (id == 0)
		return ("Xaviel NIER");
	if (id == 1)
		return ("Jseucs Thrist");
	if (id == 2)
		return ("Dolan TRUM");
	if (id == 3)
		return ("Yolo SWAGGINS");
	if (id == 4)
		return ("Sample Text");
	if (id == 5)
		return ("cdeniau");
	if (id == 6)
		return ("jwalle");
	return (NULL);
}
