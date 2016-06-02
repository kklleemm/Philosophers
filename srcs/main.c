/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:37:52 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/02 12:53:30 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
/*
static void			debug(t_table *t)
{
	int				i = 0;

	while (i < 20)
	{
		printf ("Coucou %p ======  %d\n", t, i);
		i++;
	}
}
*/
int					main(void)
{
	GLFWwindow		*win;
	t_env			*e;
	t_table			*t;

	t = table_allocation();
	t = create_threads(t);
//	debug(t); // TODO remove
	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	win = initWindow(WIDTH, HEIGHT);
	if (win)
		display(win, e);
	glfwDestroyWindow(win);
	return (0);
}
