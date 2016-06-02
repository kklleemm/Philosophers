/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:59:44 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/02 13:02:37 by cdeniau          ###   ########.fr       */
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
			sleep(1);
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
		printf ("%d\n", i);
		if (i % 2 == 1)
		{
			puts ("1");
			p = (t_philo *)t->data;
			puts ("2");
			err = pthread_create(&p->thread, NULL, &thread_philo, NULL);
			pthread_join(p->thread, NULL);
			puts ("3");
		}
		else
		{
			puts ("A");
			//printf ("id stick = %d\n", t->data->id_stick);
			s = (t_stick *)t->data;
			puts ("B");
		}
//		if (err != 0)
//			; // TODO error
		t = t->next;
		i++;
	}
	return (t);
}
