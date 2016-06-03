/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_allocation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 11:57:10 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/03 21:58:18 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static t_philo	*fill_philo(t_philo *p, int id)
{
	p->id = id;
	p->hp = MAX_LIFE;
	p->x = set_x(id);
	p->y = set_y(id);
	p->thread = NULL;
	p->state = 0;
	return (p);
}

t_philo			*table_allocation(void)
{
	int			i;
	t_philo		*p;
	t_philo		*head;

	if (!(p = malloc(sizeof(t_philo))))
		exit(-1);
	head = p;
	i = 0;
	while (i < 7)
	{
		p = fill_philo(p, i);
		if (i != 6)
		{
			if (!(p->next = malloc(sizeof(t_philo))))
				exit(-1);
			p = p->next;
		}
		else
			p->next = head;
		i += 1;
	}
	return (head);
}
