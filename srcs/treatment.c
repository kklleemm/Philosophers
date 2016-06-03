/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:53:05 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/03 11:45:22 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_table		*treatment(t_table *t)
{
	int		i;
	char	*state;
	t_table	*head;
	t_philo	*p;

	i = 0;
	head = t;
	while (i++ < 14)
	{
		if (i % 2 == 1)
		{
			p = (t_philo *)t->data;
			disp_string(p->x, p->y + 0.03, ft_strdup(p->name));
			disp_string(p->x, p->y + 0.07, ft_strdup("HP = "));
			disp_string(p->x + 0.07, p->y + 0.07, ft_itoa(p->hp));
			if (p->state == 0)
				state = ft_strdup("REST");
			else if (p->state == 1)
				state = ft_strdup("THINK");
			else if (p->state == 2)
				state = ft_strdup("EAT");
			 disp_string(p->x, p->y + 0.11, state);
		}
		t = t->next;
	}
	return (head);
}
