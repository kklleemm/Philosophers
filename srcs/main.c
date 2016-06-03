/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:37:52 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/03 11:22:28 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int					main(void)
{
	GLFWwindow		*win;
	t_env			*e;
	t_table			*t;

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	t = table_allocation();
	win = initWindow(WIDTH, HEIGHT);
	if (win)
		display(win, e, t);
	glfwDestroyWindow(win);
	return (0);
}
