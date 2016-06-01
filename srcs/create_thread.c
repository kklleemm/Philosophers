/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:59:44 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/01 15:57:15 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void					*thread_start(void *arg)
{
	struct t_thread_info	*tinfo;
	char					*uargv;
	char					*p;

	tinfo = arg;
	printf("Thread %d: top of stack near %p; argv_string=%s\n",
			tinfo->thread_num, &p, tinfo->argv_string);
	uargv = strdup(tinfo->argv_string);
	if (uargv == NULL)
		handle_error("strdup");
	for (p = uargv; *p != '\0'; p++)
		*p = ft_toupper(*p);
	return uargv;
}

int							create_threads(void)
{
	int						i;
	int						s;
	int						nb_threads;
	struct t_thread_info	*tinfo; // see philo.h

	printf("START create\n");
	nb_threads = 7;
	i = 0;
	tinfo = malloc(sizeof (struct t_thread_info) * nb_threads);
	if (tinfo == NULL)
		handle_error("malloc");
	while (i++ < nb_threads)
	{
		tinfo[i].thread_num = i;
		tinfo[i].argv_string = ft_strdup("plop"); // TODO : free
		s = pthread_create(&tinfo[i].thread_id, NULL, &thread_start, &tinfo[i]);
		if (s != 0)
			handle_error_en(s, "pthread_create");
	}
	if (s != 0)
		handle_error_en(s, "pthread_attr_destroy");
	free(tinfo);
	return (0);
}
