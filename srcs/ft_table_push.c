/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 12:25:36 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/02 18:13:40 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// TODO prev
t_table		*ft_lst_push(t_table *first, void *item)
{
	t_table	*tmp;

	if (!item)
		return (NULL);
	if (!first)
	{
		first = malloc(sizeof(t_table));
		first->data = item;
		first->next = NULL;
		first->prev = NULL;
	}
	else
	{
		tmp = first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_table));
		tmp->next->data = item;
		tmp->next->prev = tmp;
		tmp->next->next = NULL;
	}
	return (first);
}
