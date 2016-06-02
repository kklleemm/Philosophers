/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:06:14 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/02 16:15:40 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


float		set_x(int id)
{
	if (id == 1)
		return (.2);
	if (id == 3)
		return (.6);
	if (id == 5)
		return (.4);
	if (id == 7)
		return (0);
	if (id == 9)
		return (-0.4);
	if (id == 11)
		return (-0.6);
	if (id == 13)
		return (-0.2);
	return (0);
}

float		set_y(int id)
{
	if (id == 1)
		return (0.3);
	if (id == 3)
		return (0.1);
	if (id == 5)
		return (-0.1);
	if (id == 7)
		return (-0.3);
	if (id == 9)
		return (-0.1);
	if (id == 11)
		return (0.1);
	if (id == 13)
		return (0.3);
	return (0);
}

char		*get_name(int id)
{
	if (id == 1)
		return ("Xaviel NIER");
	if (id == 3)
		return ("Jseucs Thrist");
	if (id == 5)
		return ("Dolan TRUM");
	if (id == 7)
		return ("Yolo SWAGGINS");
	if (id == 9)
		return ("Sample Text");
	if (id == 11)
		return ("cdeniau");
	if (id == 13)
		return ("jwalle");
	return (NULL);
}
