/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:38:16 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/04 19:10:11 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <GLFW/glfw3.h>
# include <GLUT/glut.h>
# include <pthread.h>
# include <string.h>

# define WIDTH 1200
# define HEIGHT 1000

# define REST 0
# define THINK 1
# define EAT 2
# define WIN 3
# define LOSE 4

# define MAX_LIFE 5
# define EAT_T 1
# define REST_T 1
# define THINK_T 1
# define TIMEOUT 30

# define S_BUSY 0
# define S_FREE 1

extern int					g_sticks[7];

typedef struct				s_env
{
	int						player;
}							t_env;

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
	int						state;
	pthread_t				thread;
	struct s_philo			*next;
}							t_philo;

t_philo						*table_allocation(void);
t_philo						*join_threads(t_philo *p);
void						disp_data(t_philo *p);
t_philo						*disp_free_sticks(t_philo *p);
t_philo						*lose(t_philo *p);
float						set_x(int id);
float						set_y(int id);
char						*get_name(int id);
int							g_stick_l_free(t_philo *p);
int							g_stick_r_free(t_philo *p);
int							wait_time(t_philo *p);
void						regular_disp(t_philo *p, char *state);
void						disp_hp(float x, float y, int hp);

/*
**		GLFW functions :
*/

void						display(GLFWwindow *win, t_env *e, t_philo *p);
GLFWwindow					*initwindow(const int resx, const int resy);
void						controls(GLFWwindow *win,
		int key, int scancode, int action, int mods);
void						disp_string(float x, float y, char *str);

/*
**		Form functions :
*/

void						disp_square_green(int x, int y, float start_y);
t_philo						*create_threads(t_philo *p);

#endif
