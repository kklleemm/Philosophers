/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:53:05 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/02 15:28:29 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_table		*treatment(t_table *t)
{
	int		i;
	t_table	*head;
	t_philo	*p;

	i = 0;
	head = t;
	while (i++ < 14)
	{
		disp_string(22,22, ft_itoa(i));
		if (i % 2 == 1)
		{
			p = (t_philo *)t->data;
			disp_string(p->x, p->y, ft_itoa(p->id));
		}
		t = t->next;
	}
	return (head);
}
