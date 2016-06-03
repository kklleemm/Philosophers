/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:39:37 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/03 11:35:42 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		controls(GLFWwindow *win, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(win, GL_TRUE);
	}
}

GLFWwindow	*initWindow(const int resX, const int resY)
{
	GLFWwindow *win;

	if (!glfwInit())
		return (NULL);
	win = glfwCreateWindow(resX, resY, "Filler", NULL, NULL);
	if (!win)
	{
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(win);
	glfwSwapInterval(1);
	glfwSetKeyCallback(win, controls);
	return (win);
}

static void	join_threads(t_table *t)
{
	int				i;
	int				err;
	t_philo			*p;

	i = 0;
	err = 0;
	while (i < 14)
	{
		if (i % 2 == 1)
		{
			p = (t_philo *)t->data;
			err = pthread_join(p->thread, NULL);
			if (err != 0)
				write (1, "error\n", 6); // TODO error
			else
				write (1, "thread running\n", 15); // TODO error
		}
		t = t->next;
		i++;	
	}
}

void		display(GLFWwindow *win, t_env *e, t_table *t)
{
	int		i;

	i = 0;
	glViewport(0, 0, WIDTH, HEIGHT);
	glClear(GL_COLOR_BUFFER_BIT);
	while (!glfwWindowShouldClose(win))
	{
		if (i == 0)
			t = create_threads(t);
		if (i == 0)
		{
			join_threads(t);
			i += 1;
		}
		glfwSwapBuffers(win);
		t = treatment(t);
		glfwPollEvents();
	}
	e->player = 1;
	glfwTerminate();
}
