/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:53:05 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/04 19:06:10 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void		disp_data(t_philo *p)
{
	int		i;
	char	*state;

	i = 0;
	p = disp_free_sticks(p);
	while (i++ < 7)
	{
		if (p->state == REST)
			state = ft_strdup("REST");
		else if (p->state == THINK)
			state = ft_strdup("THINK");
		else if (p->state == EAT)
			state = ft_strdup("EAT");
		if (p->state == WIN)
			disp_string(-.2, .15,
					ft_strdup("Now, it is time... To DAAAAAAAANCE ! ! !"));
		else if (p->state == LOSE)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			disp_string(0, 0, ft_strdup("Game Over, press esc to quit"));
		}
		else
			regular_disp(p, state);
		p = p->next;
	}
}
