/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:37:52 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/01 16:13:48 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
	create_threads();
	return (0);
}
