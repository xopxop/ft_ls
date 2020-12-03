/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 02:17:07 by dthan             #+#    #+#             */
/*   Updated: 2020/06/11 02:30:02 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void		ft_separate_hidden_and_non_hidden(t_node *lst)
{
	t_node	*ptr;
	int		is_in_order;

	is_in_order = NO;
	while (is_in_order == NO && (lst))
	{
		ptr = lst;
		is_in_order = YES;
		while (ptr->next)
		{
			if (!ptr->status.is_hidden && ptr->next->status.is_hidden)
			{
				ft_swap_stat(&ptr->status, &ptr->next->status);
				is_in_order = NO;
			}
			ptr = ptr->next;
		}
	}
}

void		ft_sort_hidden(t_node *lst)
{
	t_node	*ptr;
	int		is_in_order;

	is_in_order = NO;
	while (is_in_order == NO && (lst))
	{
		ptr = lst;
		is_in_order = YES;
		while (ptr->next)
		{
			if (ptr->status.is_hidden && ptr->next->status.is_hidden \
			&& (ft_strcmp(ptr->status.name, ptr->next->status.name) > 0))
			{
				ft_swap_stat(&ptr->status, &ptr->next->status);
				is_in_order = NO;
			}
			ptr = ptr->next;
		}
	}
}

void		ft_sort_non_hidden(t_node *lst)
{
	t_node	*ptr;
	int		is_in_order;

	is_in_order = NO;
	while (is_in_order == NO && (lst))
	{
		ptr = lst;
		is_in_order = YES;
		while (ptr->next)
		{
			if (!ptr->status.is_hidden && !ptr->status.is_hidden \
			&& (ft_strcmp(ptr->status.name, ptr->next->status.name) > 0))
			{
				ft_swap_stat(&ptr->status, &ptr->next->status);
				is_in_order = NO;
			}
			ptr = ptr->next;
		}
	}
}

static void	ft_swap_file_info(t_stat *file1, t_stat *file2)
{
	file1->name = file2->name;
	file1->path = file2->path;
	file1->user_name = file2->user_name;
	file1->group_name = file2->group_name;
	file1->time = file2->time;
	file1->file_permission = file2->file_permission;
	file1->type = file2->type;
	file1->is_hidden = file2->is_hidden;
	file1->allow_open = file2->allow_open;
	file1->stats = file2->stats;
	file1->min_of = file2->min_of;
	file1->path_sym_link = file2->path_sym_link;
}

void		ft_swap_stat(t_stat *file1, t_stat *file2)
{
	t_stat temp;

	ft_swap_file_info(&temp, file1);
	ft_swap_file_info(file1, file2);
	ft_swap_file_info(file2, &temp);
}
