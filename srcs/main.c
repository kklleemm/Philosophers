/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:37:52 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/03 17:12:04 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int					main(void)
{
	GLFWwindow		*win;
	t_env			*e;
	t_philo			*p;

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	p = table_allocation();
	win = initWindow(WIDTH, HEIGHT);
	if (win)
		display(win, e, p);
	glfwDestroyWindow(win);
	return (0);
}
