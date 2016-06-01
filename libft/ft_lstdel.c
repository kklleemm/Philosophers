/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 12:35:55 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/06 14:41:30 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_struct.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nxt;

	if (!alst || !*alst)
		return ;
	lst = *alst;
	while (lst)
	{
		nxt = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nxt;
	}
	*alst = NULL;
}
