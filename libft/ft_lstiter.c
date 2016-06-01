/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 12:36:07 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/06 12:52:44 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_struct.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*nxt;

	while (lst)
	{
		nxt = lst->next;
		f(lst);
		lst = nxt;
	}
}
