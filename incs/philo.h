/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:38:16 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/01 15:12:45 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./libft.h"
# include <stdlib.h>
# include <GLFW/glfw3.h>
# include <GLUT/glut.h>
# include <stdio.h> // TODO remove

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


#endif
