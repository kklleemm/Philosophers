/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:53:05 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/03 18:19:21 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void		disp_data(t_philo *p)
{
	int		i;
	char	*state;

	i = 0;
	while (p->id != i)
		p = p->next;
	while (i < 7)
	{
		disp_string(p->x, p->y + 0.07, ft_strdup("HP = "));
		disp_string(p->x + 0.07, p->y + 0.07, ft_itoa(p->hp));
		if (p->state == 0)
		{
			state = ft_strdup("REST");
		}
		else if (p->state == 1)
		{
			state = ft_strdup("THINK");
		}
		else if (p->state == 2)
		{
			state = ft_strdup("EAT");
		}
		disp_string(p->x, p->y + 0.11, state);
		disp_string(p->x, p->y + 0.15, ft_strdup("ID = "));
		disp_string(p->x + 0.07, p->y + 0.15, ft_itoa(p->id));
		p = p->next;
		i++;
	}
	p = p->next;
}
