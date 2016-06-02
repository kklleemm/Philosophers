/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:38:16 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/02 16:14:32 by cdeniau          ###   ########.fr       */
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

# define WIDTH 1200
# define HEIGHT 1000

typedef struct	s_env
{
	int			player;
}				t_env;

/*
**		philo functions :
*/

void						init_env(t_env *e);

typedef struct				s_table
{
	void					*data;
	struct s_table			*next;
	struct s_table			*prev;
}							t_table;

typedef struct				s_stick
{
	int						id_stick;
	pthread_mutex_t			mutex;
}							t_stick;

typedef struct				s_philo
{
	short					id;
	short					hp;
	float					x;
	float					y;
	char					*name;
	pthread_t				thread;
}							t_philo;

t_table						*table_allocation(void);
t_table						*ft_lst_push(t_table *t, void *item);
t_table						*treatment(t_table *t);
float						set_x(int id);
float						set_y(int id);
char						*get_name(int id);

/*
**		GLFW functions :
*/

void						display(GLFWwindow *win, t_env *e, t_table *t);
GLFWwindow					*initWindow(const int resX, const int resY);
void						controls(GLFWwindow *win, int key, int scancode, int action, int mods);
void						disp_string(float x, float y, char *str);

/*
**		Form functions :
*/

void						disp_square_green(int x, int y, float start_y);
t_table						*create_threads(t_table *t);

#endif
