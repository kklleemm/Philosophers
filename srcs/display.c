/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:39:37 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/02 15:18:21 by cdeniau          ###   ########.fr       */
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

void		display(GLFWwindow *win, t_env *e, t_table *t)
{
	glViewport(0, 0, WIDTH, HEIGHT);
	glClear(GL_COLOR_BUFFER_BIT);
	while (!glfwWindowShouldClose(win))
	{
//		glClear(GL_COLOR_BUFFER_BIT);
		disp_square_green(5, 5, 0);
		glfwSwapBuffers(win);
		t = treatment(t);
		glfwPollEvents();
		disp_square_green(5, 5, 0);
	}
	e->player = 1;
	glfwTerminate();
}
