/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:59:44 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/03 18:54:06 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int					sticks[7] = {1, 1, 1, 1, 1, 1, 1};
pthread_mutex_t 	 oqp;

static void			*thread_philo(void *arg)
{
	t_philo			*p;

	p = (t_philo *)arg;
	printf ("mutex lock p->id = %d\n", p->id);
	while (1)
	{
		pthread_mutex_lock(&oqp);
		if (p->state == EAT)
		{
			p->state = REST;
			sticks[p->id] = S_FREE;
			p->id == 6 ? (sticks[0] = S_FREE) : (sticks[p->id + 1] = S_FREE);
			p->hp -= 1;
			pthread_mutex_unlock(&oqp);
			usleep(REST_T * 1000000);
		}
		else if (sticks[p->id] == S_FREE
				&& (p->id == 6 ? sticks[0] : sticks[p->id + 1]) == S_FREE)
		{
			sticks[p->id] = S_BUSY;
			p->id == 6 ? (sticks[0] = S_BUSY) : (sticks[p->id + 1] = S_BUSY);
			p->state = EAT;
			p->hp = MAX_LIFE;
			pthread_mutex_unlock(&oqp);
			usleep(EAT_T * 1000000);
		} else {
			p->state = THINK;
			p->hp -= 1;
			pthread_mutex_unlock(&oqp);
			usleep(THINK_T * 1000000);
		}
		if (p->hp <= 0)
		{
			printf ("%d died\n", p->id);
			break ;
		}
		printf ("%d : %d with %d HP\n", p->id, p->state, p->hp);
	}
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
		exit (-1);
	while (i < 7)
	{
		err = pthread_create(&p->thread, NULL, &thread_philo, p);
		if (err != 0)
			exit (-1);
		p = p->next;
		i++;
	}
	return (head);
}
