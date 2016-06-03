/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_eat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 11:46:39 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/03 11:53:30 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_table		*p_rest(t_table *t)
{
	t_philo	*p;

	p = (t_philo *)t->data;
	p->state = 0;
	sleep(1); // TODO use constant
	p->hp -= 1;
	return (t);
}

t_table		*p_eat(t_table *t)
{
	t_philo	*p;
	t_stick	*s;

	p = (t_philo *)t->data;
	p->state = 2;
	sleep(1); // TODO use constant
	p->hp = 3;
	s = (t_stick *)t->prev->data;
	pthread_mutex_unlock(&s->mutex);
	s = (t_stick *)t->next->data;
	pthread_mutex_unlock(&s->mutex);
	return (p_rest(t));
}
