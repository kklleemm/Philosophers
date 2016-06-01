/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:38:16 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/01 15:29:25 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <pthread.h>
#include <string.h>
# include <stdio.h> // TODO remove
# include <errno.h> // TODO remove ?
# define handle_error_en(en, msg) \
	do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)
# define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

typedef struct				t_thread_info /* Used as argument to thread_start() */
{
	pthread_t				thread_id;        /* ID returned by pthread_create() */
	int						thread_num;       /* Application-defined thread # */
	char					*argv_string;      /* From command-line argument */
}							s_thread_info;

typedef struct				s_philo
{
	short					sticks;
	short					hp;
	struct t_thread_info	*tinfo;
	struct s_philo			*next;
	struct s_philo			*prev;
}							t_philo;

int							create_threads(void);

#endif
