/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:37:52 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/01 13:40:49 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void disp_square_green(int x, int y, float start_y)
{
	float x1;
	float y1;
	float size = 0.03;

	x1 = -0.94 + ((float)x * 0.05);
	y1 = start_y - ((float)y * 0.05);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x1,y1 - size,-1.0f);
	glVertex3f(x1,y1,-1.0f);
	glVertex3f(x1 + size,y1,-1.0f);
	glVertex3f(x1 + size,y1 - size,-1.0f);
	glEnd();
}

void controls(GLFWwindow *win, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(win, GL_TRUE);
	}
}

GLFWwindow *initWindow(const int resX, const int resY)
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
	printf("Rendrerer : %s\n", glGetString(GL_RENDERER));
	printf("OpenGL version : %s\n", glGetString(GL_VERSION));
	return (win);
}

void display(GLFWwindow *win, t_env *e)
{
	glViewport(0, 0, 1000, 1000);
	glClear(GL_COLOR_BUFFER_BIT);
	while (!glfwWindowShouldClose(win))
	{
			disp_square_green(5, 5, 0);
			glfwSwapBuffers(win);
			glfwPollEvents();
			disp_square_green(5, 5, 0);
			
	}
	e->player = 1;
	glfwTerminate();
}

void	init_env(t_env *e)
{
	e->player = 0;
}

int		main(void)
{
	GLFWwindow *win;
	t_env *e;

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	win = initWindow(WIDTH, HEIGHT);
	if (win)
		display(win, e);
	glfwDestroyWindow(win);
	return (0);
}
