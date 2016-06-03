/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:59:44 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/03 17:12:09 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int					sticks[7] = { 1, 1, 1, 1, 1, 1, 1 };
pthread_mutex_t 	 oqp;

static void			*thread_philo(void *arg)
{
	t_philo			*p;

	puts("create thread");
	p = (t_philo *)arg;
	pthread_mutex_lock(&oqp);
	if (sticks[p->id] == 1
			&& (p->id == 7 ? sticks[0] : sticks[p->id + 1]) == 1)
	{
		sticks[p->id] = 0;
		p->id == 7 ? (sticks[0] = 0) : (sticks[p->id + 1] = 0);
		p->state = 2;
	} else {
		p->state = 1;
	}
	pthread_mutex_unlock(&oqp);
	return (NULL);
}

t_philo				*create_threads(t_philo *p)
{
	int				i;
	int				err;
	t_philo			*head;

	i = 0;
	head = p;
	if (pthread_mutex_init(&oqp, NULL) != 0)
		write (1, "oh no\n", 6);
	while (i < 7)
	{
		err = pthread_create(&p->thread, NULL, &thread_philo, p);
		if (err != 0)
			puts("create fail"); // TODO error
		p = p->next;
		i++;
	}
	return (head);
}
