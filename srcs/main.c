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
#include <stdlib.h>

#define EATING ft_putstr("Eating...\n");
#define THINKING ft_putstr("thinkng...\n");
#define RESTING ft_putstr("Resting...\n");


int	can_eat(t_env *e)
{
	if (e->player == 1)
		return (1);
	return (0);
}



void	*philosopher(void *arg)
{
	while (1)
	{
		if (can_eat((t_env*)arg))
		{
			EATING;
			e->player = 2;
			RESTING;
		}
		else
			THINKING;
	}
}

void *buzz_function(void *arg)
{

	while (1)
	{
		if ((t_env*)arg->player == 2)
		{
			printf("arg buzz = %s\n", (char *)arg);
			sleep(1);
			(t_env*)arg->player = 1;
		}
		//pthread_exit(NULL);
	}
}

void 

int		main(void)
{
	//GLFWwindow *win;
	t_env *e;

	printf("START main\n");
	e = (t_env *)malloc(sizeof(t_env));
	e->player = 1;

	pthread_t philo;
	pthread_t buzz;
	//char	*str1 = ft_strdup("plop");
	// char	*str2 = ft_strdup("BORDEL");

	pthread_create(&philo, NULL, philosopher, (void*)e);
	pthread_create(&buzz, NULL, buzz_function, (void*)e);

	pthread_join(philo, NULL);
	//pthread_join(buzz, NULL);

	/*create_threads();
	if (!e)
		exit (printf("ERROR\n"));
	init_env(e);
	win = initWindow(WIDTH, HEIGHT);
	if (win)
		display(win, e);
	 glfwDestroyWindow(win);*/
	return (0);
}
