/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:39:37 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/04 18:27:14 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			controls(GLFWwindow *win, int key, int scancode,
		int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(win, GL_TRUE);
	}
}

GLFWwindow		*initwindow(const int resx, const int resy)
{
	GLFWwindow	*win;

	if (!glfwInit())
		return (NULL);
	win = glfwCreateWindow(resx, resy, "Filler", NULL, NULL);
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

t_philo			*join_threads(t_philo *p)
{
	int			i;
	int			err;
	t_philo		*head;

	head = p;
	i = 0;
	while (i < 7)
	{
		err = pthread_join(p->thread, NULL);
		p = p->next;
		i++;
	}
	return (head);
}

void			display(GLFWwindow *win, t_env *e, t_philo *p)
{
	(void)e;
	glClear(GL_COLOR_BUFFER_BIT);
	p = create_threads(p);
	while (!glfwWindowShouldClose(win))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		disp_data(p);
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	glfwTerminate();
}
