/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 19:00:08 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/04 19:06:06 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	disp_stick_l(float x, float y)
{
	float x1;
	float y1;

	x1 = x - 0.15;
	y1 = y + 0.15;
	glColor3f(0.4f, 0.4f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x1, y1, 1.0f);
	glVertex3f(x1 + 0.05, y1 + 0.2, 1.0f);
	glVertex3f(x1 + 0.055, y1 + 0.22, 1.0f);
	glVertex3f(x1 + 0.005, y1 - 0.02, 1.0f);
	glEnd();
}

static void	disp_stick_r(float x, float y)
{
	float x1;
	float y1;

	x1 = x + 0.15;
	y1 = y + 0.15;
	glColor3f(0.4f, 0.4f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x1, y1, 1.0f);
	glVertex3f(x1 + 0.05, y1 + 0.2, 1.0f);
	glVertex3f(x1 + 0.055, y1 + 0.22, 1.0f);
	glVertex3f(x1 + 0.005, y1 - 0.02, 1.0f);
	glEnd();
}

static void	disp_philo(float x, float y)
{
	float x1;
	float y1;
	float size_sq;

	size_sq = 0.3;
	x1 = x - 0.15;
	y1 = y + 0.15;
	glEnd();
}

void		regular_disp(t_philo *p, char *state)
{
	disp_string(p->x, p->y + 0.11, state);
	disp_string(p->x, p->y + 0.15, ft_strdup("ID = "));
	disp_string(p->x + 0.07, p->y + 0.15, ft_itoa(p->id));
	disp_philo(p->x, p->y);
	disp_hp(p->x, p->y + 0.1, p->hp);
	disp_string(p->x - 0.02, p->y, ft_strdup(get_name(p->id)));
	if (p->state == EAT)
	{
		disp_stick_l(p->x, p->y);
		disp_stick_r(p->x, p->y);
	}
}
