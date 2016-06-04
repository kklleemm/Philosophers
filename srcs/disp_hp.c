/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_hp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 19:02:56 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/04 19:04:05 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void		disp_hearth(int hp, float x, float y, float size)
{
	int			i;
	float		size_sq;
	float		x1;
	float		y1;

	i = 0;
	size_sq = 0.04;
	while (i < hp)
	{
		x1 = x - size + 0.01 + (i * (size_sq + 0.012));
		y1 = y + 0.03 - 0.01;
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
		glVertex3f(x1, y1, .0f);
		glVertex3f(x1 + size_sq, y1, .0f);
		glVertex3f(x1 + size_sq, y1 - size_sq, .0f);
		glVertex3f(x1, y1 - size_sq, .0f);
		glEnd();
		i++;
	}
}

static void		disp_line(float x1, float y1, float x2, float y2)
{
	glColor3f(1.0f, 1.0f, -1.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
}

void			disp_hp(float x, float y, int hp)
{
	float		size;

	size = MAX_LIFE * 0.027;
	disp_line(x - size, y + 0.03, x + size, y + 0.03);
	disp_line(x + size, y + 0.03, x + size, y - 0.03);
	disp_line(x - size, y + 0.03, x - size, y - 0.03);
	disp_line(x - size, y - 0.03, x + size, y - 0.03);
	disp_hearth(hp, x, y, size);
}
