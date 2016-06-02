/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:59:44 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/02 15:16:58 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void			*thread_philo(void *arg)
{
	int				nb_sticks = 2; // TODO search for sticks

	(void) arg;
	while (1)
	{
		//nb_sticks = search_for_sticks();
		if (nb_sticks == 2)
		{
			//pthread_mutex_lock (&stick);
			//pthread_cond_signal (&eat);
			//pthread_mutex_unlock (&stick);
			puts ("RESTING\n");
			nb_sticks = 0;
//			sleep(1);
		}
		else if (nb_sticks == 1)
		{
			sleep(1);
		}
		break;
	}
	pthread_exit(NULL);
}

t_table				*create_threads(t_table *t)
{
	int				i;
	int				err;
	t_philo			*p;
	t_stick			*s;

	i = 0;
	while (i < 14)
	{
		if (i % 2 == 1)
		{
			p = (t_philo *)t->data;
			err = pthread_create(&p->thread, NULL, &thread_philo, NULL);
			if (err != 0)
				; // TODO error
			pthread_join(p->thread, NULL);
		}
		else
			s = (t_stick *)t->data;
		t = t->next;
		i++;
	}
	return (t);
}
