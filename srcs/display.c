/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:39:37 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/03 17:12:45 by cdeniau          ###   ########.fr       */
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

static void	join_threads(t_philo *p)
{
	int				i;
	int				err;

	i = 0;
	err = 0;
	while (p->id != i)
		p = p->next;
	while (i < 7)
	{
		err = pthread_join(p->thread, NULL);
		if (err != 0)
			write (1, "error\n", 6); // TODO error
		p = p->next;
		i++;	
	}
	p = p->next;
}

void		display(GLFWwindow *win, t_env *e, t_philo *p)
{
	(void)e;
	glViewport(0, 0, WIDTH, HEIGHT);
	glClear(GL_COLOR_BUFFER_BIT);
	p = create_threads(p);
	join_threads(p);
	while (!glfwWindowShouldClose(win))
	{
		glfwSwapBuffers(win);
		disp_data(p);
		glfwPollEvents();
	}
	glfwTerminate();
}
