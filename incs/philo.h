/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:38:16 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/01 16:15:06 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <GLFW/glfw3.h>
# include <GLUT/glut.h>
# include <pthread.h>
#include <string.h>
# include <stdio.h> // TODO remove
# include <errno.h> // TODO remove ?
# define handle_error_en(en, msg) \
	do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)
# define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

# define WIDTH 1200
# define HEIGHT 1000

typedef struct	s_env
{
	int			player;
}				t_env;

/*
**		philo functions :
*/

void		init_env(t_env *e);

/*
**		GLFW functions :
*/

void		display(GLFWwindow *win, t_env *e);
GLFWwindow	*initWindow(const int resX, const int resY);
void		controls(GLFWwindow *win, int key, int scancode, int action, int mods);

/*
**		Form functions :
*/

void		disp_square_green(int x, int y, float start_y);

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
