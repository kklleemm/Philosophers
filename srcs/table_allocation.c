/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_allocation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 11:57:10 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/03 11:41:27 by cdeniau          ###   ########.fr       */
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
	p->state = 0;
	return (p);
}

static t_stick	*fill_stick(int id)
{
	t_stick		*s;

	if (!(s = malloc (sizeof (t_stick))))
		; // TODO exit
	s->id_stick = id;
	if (pthread_mutex_init(&s->mutex, NULL) != 0)
	{
		write (1, "mutex init failed", 17);
		exit (0);
	}
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
