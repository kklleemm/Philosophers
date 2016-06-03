/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:38:16 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/03 17:14:11 by cdeniau          ###   ########.fr       */
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

typedef struct				s_philo
{
	short					id;
	short					hp;
	float					x;
	float					y;
	int						state; // 0 => REST | 1 => THINK | 2 => EAT
	pthread_t				thread;
	struct s_philo			*next;
}							t_philo;

t_philo						*table_allocation(void);
void						disp_data(t_philo *p);
float						set_x(int id);
float						set_y(int id);
char						*get_name(int id);

/*
**		GLFW functions :
*/

void						display(GLFWwindow *win, t_env *e, t_philo *p);
GLFWwindow					*initWindow(const int resX, const int resY);
void						controls(GLFWwindow *win, int key, int scancode, int action, int mods);
void						disp_string(float x, float y, char *str);

/*
**		Form functions :
*/

void						disp_square_green(int x, int y, float start_y);
t_philo						*create_threads(t_philo *p);

#endif
