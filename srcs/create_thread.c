/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:59:44 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/04 16:33:34 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

pthread_mutex_t			g_oqp = PTHREAD_MUTEX_INITIALIZER;
int						g_sticks[7] = {1, 1, 1, 1, 1, 1, 1};

static t_philo			*eat(t_philo *p)
{
	g_sticks[p->id] = S_BUSY;
	if (p->id == 6)
		g_sticks[0] = S_BUSY;
	else
		g_sticks[p->id + 1] = S_BUSY;
	p->state = EAT;
	p->hp = MAX_LIFE;
	pthread_mutex_unlock(&g_oqp);
	return (p);
}

static t_philo			*rest(t_philo *p)
{
	p->state = REST;
	g_sticks[p->id] = S_FREE;
	if (p->id == 6)
		g_sticks[0] = S_FREE;
	else
		g_sticks[p->id + 1] = S_FREE;
	p->hp -= 1;
	pthread_mutex_unlock(&g_oqp);
	return (p);
}

static t_philo			*think(t_philo *p)
{
	p->state = THINK;
	p->hp -= 1;
	pthread_mutex_unlock(&g_oqp);
	return (p);
}

static t_philo			*lose(t_philo *p)
{
	int					i;

	i = 0;
	p->state = LOSE;
	while (i < 18)
	{
		p->hp = 0;
		p = p->next;
		i++;
	}
	return (p);
}

static int				g_sticks_free(t_philo *p)
{
	if (g_sticks[p->id] != S_FREE)
		return (0);
	if ((p->id == 6 && g_sticks[0] != S_FREE)
			|| (p->id != 6 && g_sticks[p->id + 1] != S_FREE))
		return (0);
	return (1);
}

static int				wait_time(t_philo *p)
{
	if (p->state == REST)
		return (REST_T);
	if (p->state == EAT)
		return (EAT_T);
	if (p->state == THINK)
		return (THINK_T);
	return (0);
}

static void				*thread_philo(void *arg)
{
	t_philo				*p;
	int					wait;

	p = (t_philo *)arg;
	wait = 0;
	while (1)
	{
		pthread_mutex_lock(&g_oqp);
		if (p->state == EAT)
			p = rest(p);
		else if (1 == g_sticks_free(p) && p->hp <= p->next->hp)
			p = eat(p);
		else
			p = think(p);
		usleep(1000000 * wait_time(p));
		wait += wait_time(p);
		if (p->hp <= 0)
		{
			p = lose(p);
			return (NULL);
		}
		if (wait >= TIMEOUT)
		{
			p->state = WIN;
			return (NULL);
		}
	}
}

t_philo					*create_threads(t_philo *p)
{
	int					i;
	int					err;
	t_philo				*head;

	i = 0;
	head = p;
	if (pthread_mutex_init(&g_oqp, NULL) != 0)
		exit(-1);
	while (i < 7)
	{
		err = pthread_create(&p->thread, NULL, &thread_philo, p);
		if (err != 0)
			exit(-1);
		p = p->next;
		i++;
	}
	return (head);
}
