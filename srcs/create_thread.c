/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:59:44 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/02 20:54:52 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#define handle_error_en(en, msg) \
	do { errno = en; perror(msg);  } while (0)
static int			get_nb_sticks(t_table *t)
{
	int				ret;
	int				err;
	t_stick			*s;
	t_philo			*p;

	p = (t_philo *)t->data;
	printf ("id_philo = %d\n", p->id);
	ret = 0;
	s = (t_stick *)t->next->data;
	printf ("id_stick = %d\n", s->id_stick);
	err = pthread_mutex_trylock(&s->mutex);
	if (err != 0)
		handle_error_en(err, "pthread_mutex_trylock #1");
	else
		ret += 1;
	s = (t_stick *)t->prev->data;
	printf ("id_stick = %d\n", s->id_stick);
	err = pthread_mutex_trylock(&s->mutex);
	if (err != 0)
		handle_error_en(err, "pthread_mutex_trylock #2");
	else
		ret += 1;
	if (ret == 2)
		p->hp = 3; // TODO use const
	return (ret);
}

static void			*thread_philo(void *arg)
{
	int				nb_sticks;
	int				i;
	int				max;
	t_table			*t;
	t_stick			*s;

	i = 0;
	t = (t_table *)arg;
	max = t->cur;
	while (i < max)
	{
		t = t->next;
		i++;		
	}
	nb_sticks = get_nb_sticks(t);
	if (nb_sticks == 2)
	{
		puts ("EATING\n");
		sleep(1); // TODO use constant
		s = (t_stick *)t->prev->data;
		pthread_mutex_unlock(&s->mutex);
		s = (t_stick *)t->next->data;
		pthread_mutex_unlock(&s->mutex);
		// TODO set HP to MAX_HP
		puts ("RESTING\n");
		sleep(1); // TODO use constant
	}
	else if (nb_sticks == 1)
	{
		puts ("THINKING\n");
		sleep(1); // TODO use constant
	}
	else
	{
		puts("ZERO");
	}
	return (NULL);
	//pthread_exit(NULL);
}

t_table				*create_threads(t_table *t)
{
	int				i;
	int				err;
	t_philo			*p;

	i = 0;
	while (i < 14)
	{
		t->cur = i;
		if (i % 2 == 1)
		{
			p = (t_philo *)t->data;
			err = pthread_create(&p->thread, NULL, &thread_philo, (void *)t);
			if (err != 0)
				; // TODO error
			pthread_join(p->thread, NULL);
			printf ("join p=%d\n", p->id);
		}
		t = t->next;
		i++;
	}
	return (t);
}
