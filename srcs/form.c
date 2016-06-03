/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:55:50 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/03 22:00:40 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		disp_square_green(int x, int y, float start_y)
{
	float	x1;
	float	y1;
	float	size;

	size = 0.03;
	x1 = -0.94 + ((float)x * 0.05);
	y1 = start_y - ((float)y * 0.05);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x1, y1 - size, -1.0f);
	glVertex3f(x1, y1, -1.0f);
	glVertex3f(x1 + size, y1, -1.0f);
	glVertex3f(x1 + size, y1 - size, -1.0f);
	glEnd();
}
