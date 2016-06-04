/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_free_sticks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 18:47:20 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/04 18:48:44 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_philo					*disp_free_sticks(t_philo *p)
{
	int					i;
	float				x1;
	float				y1;
	t_philo				*head;

	head = p;
	i = 0;
	while (i < 7)
	{
		if (g_sticks[i] == 1)
		{
			x1 = p->x + 0.05;
			y1 = p->y + 0.15;
			glColor3f(0.8f, 0.4f, 0.0f);
			glBegin(GL_QUADS);
			glVertex3f(x1, y1, 1.0f);
			glVertex3f(x1 + 0.05, y1 + 0.2, 1.0f);
			glVertex3f(x1 + 0.055, y1 + 0.22, 1.0f);
			glVertex3f(x1 + 0.005, y1 - 0.02, 1.0f);
			glEnd();
		}
		p = p->next;
		i++;
	}
	return (head);
}
