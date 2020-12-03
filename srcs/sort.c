/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 22:01:27 by dthan             #+#    #+#             */
/*   Updated: 2020/06/11 02:30:02 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_sort_alphabet(t_node *lst)
{
	ft_separate_hidden_and_non_hidden(lst);
	ft_sort_hidden(lst);
	ft_sort_non_hidden(lst);
}

void	ft_reverse(t_node **lst)
{
	t_node	*cur;
	t_node	*pre;
	t_node	*next;

	cur = *lst;
	pre = NULL;
	next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	if (pre != NULL)
		*lst = pre;
}

void	ft_sort_time(t_node *lst)
{
	int		is_in_order;
	t_node	*ptr;

	is_in_order = NO;
	while (is_in_order == NO && (lst))
	{
		ptr = lst;
		is_in_order = YES;
		while (ptr->next)
		{
			if (ft_cmp_time(ptr, ptr->next))
			{
				ft_swap_stat(&ptr->status, &ptr->next->status);
				is_in_order = NO;
			}
			ptr = ptr->next;
		}
	}
}

void	ft_sort(t_node **lst, int options)
{
	ft_sort_alphabet(*lst);
	if (options & SORT_BY_NEWEST_FIRST)
		ft_sort_time(*lst);
	if (options & REVERSE_ORDER)
		ft_reverse(lst);
}
