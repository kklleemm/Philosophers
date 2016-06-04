/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 18:35:33 by cdeniau           #+#    #+#             */
/*   Updated: 2016/06/04 18:36:00 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int			wait_time(t_philo *p)
{
	if (p->state == REST)
		return (REST_T);
	if (p->state == EAT)
		return (EAT_T);
	if (p->state == THINK)
		return (THINK_T);
	return (0);
}
