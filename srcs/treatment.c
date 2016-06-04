/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:53:05 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/04 16:31:27 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void		disp_line(float x1, float y1, float x2, float y2)
{
	glColor3f(1.0f, 1.0f, -1.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
}

static void	disp_hearth(int hp, float x, float y, float size)
{
	int		i;
	float	size_sq;
	float	x1;
	float	y1;

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

static void	disp_hp(float x, float y, int hp)
{
	float size;

	size = MAX_LIFE * 0.027;
	disp_line(x - size, y + 0.03, x + size, y + 0.03);
	disp_line(x + size, y + 0.03, x + size, y - 0.03);
	disp_line(x - size, y + 0.03, x - size, y - 0.03);
	disp_line(x - size, y - 0.03, x + size, y - 0.03);
	disp_hearth(hp, x, y, size);
}

static void	disp_stick(float x, float y)
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

static void	disp_philo(float x, float y)
{
	float x1;
	float y1;
	float size_sq;

	size_sq = 0.3;
	x1 = x - 0.15;
	y1 = y + 0.15;
	glColor3f(0.7f, 0.7f, 0.7f);
	glBegin(GL_QUADS);
	glVertex3f(x1, y1, 1.0f);
	glVertex3f(x1 + size_sq, y1, 1.0f);
	glVertex3f(x1 + size_sq, y1 - size_sq * 1.5, 1.0f);
	glVertex3f(x1, y1 - size_sq * 1.5, 1.0f);
	glEnd();
}

void		disp_data(t_philo *p)
{
	int		i;
	char	*state;

	i = 0;
	while (i < 7)
	{
		if (p->state == REST)
			state = ft_strdup("REST");
		else if (p->state == THINK)
			state = ft_strdup("THINK");
		else if (p->state == EAT)
			state = ft_strdup("EAT");
		if (p->state == WIN)
		{
			disp_string(-.2, .15,
					ft_strdup("Now, it is time... To DAAAAAAAANCE ! ! !"));
			state = ft_strdup("WIN");
		}
		else if (p->state == LOSE)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			disp_string(0, 0, ft_strdup("Game Over, press esc to quit"));
		}
		else
		{
			disp_string(p->x, p->y + 0.11, state);
			disp_string(p->x, p->y + 0.15, ft_strdup("ID = "));
			disp_string(p->x + 0.07, p->y + 0.15, ft_itoa(p->id));
			disp_philo(p->x, p->y);
			disp_hp(p->x, p->y + 0.1, p->hp);
			disp_string(p->x - 0.02, p->y, ft_strdup(get_name(p->id)));
			disp_stick(p->x, p->y);
		}
		p = p->next;
		i++;
	}
	p = p->next;
}
