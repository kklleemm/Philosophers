/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_allocation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 11:57:10 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/02 16:18:45 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static t_philo	*fill_philo(int id)
{
	t_philo		*p;

	if (!(p = malloc (sizeof (t_philo))))
		; // TODO exit
	p->id = id;
	p->name = get_name(id);
	p->hp = 3; // TODO define
	p->x = set_x(id);
	p->y = set_y(id);
	p->thread = NULL; // TODO check this
	return (p);
}

static t_stick	*fill_stick(int id)
{
	t_stick		*s;

	if (!(s = malloc (sizeof (t_stick))))
		; // TODO exit
	s->id_stick = id;
	pthread_mutex_init(&s->mutex, NULL);
	return (s);
}

t_table			*table_allocation(void)
{
	int			i;
	t_table		*t;
	t_table		*head;

	t = NULL;
	i = 0;
	while (i < 14)
	{
		printf ("%d\n", i);
		if (i % 2 == 1)
			t = ft_lst_push(t, fill_philo(i));
		else
			t = ft_lst_push(t, fill_stick(i));
		i++;
	}
	head = t;
	while (t->next != NULL) // TODO not this
		t = t->next;
	t->next = head;
	return (t);
}
