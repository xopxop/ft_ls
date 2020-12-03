/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longlist_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 01:14:08 by dthan             #+#    #+#             */
/*   Updated: 2020/06/11 02:33:26 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

int		ft_blockct(t_node *lst, int options)
{
	int total_block;

	total_block = 0;
	while (lst)
	{
		if (!(options & LIST_HIDDEN) && lst->status.is_hidden == YES)
			;
		else
			total_block += lst->status.stats.st_blocks;
		lst = lst->next;
	}
	return (total_block);
}

void	ft_get_max(t_max *max, t_node *lst, int options)
{
	while (lst)
	{
		if (!(options & LIST_HIDDEN) && lst->status.is_hidden == YES)
			;
		else
		{
			if (max->width_of_link < lst->status.min_of.width_of_link)
				max->width_of_link = lst->status.min_of.width_of_link;
			if (max->width_of_user_name < lst->status.min_of.width_of_user_name)
				max->width_of_user_name = lst->status.min_of.width_of_user_name;
			if (max->width_of_group_name < \
				lst->status.min_of.width_of_group_name)
				max->width_of_group_name = \
					lst->status.min_of.width_of_group_name;
			if (max->width_of_size < lst->status.min_of.width_of_size)
				max->width_of_size = lst->status.min_of.width_of_size;
		}
		lst = lst->next;
	}
}

void	ft_print_long_list(t_node *node, t_max max)
{
	ft_printf("%c%s %*u %*s  %*s  %*d %s %s", node->status.type, \
	node->status.file_permission, max.width_of_link, \
	node->status.stats.st_nlink, max.width_of_user_name, \
	node->status.user_name, max.width_of_group_name, \
	node->status.group_name, max.width_of_size, node->status.stats.st_size, \
	node->status.time, node->status.name);
	if (node->status.type == 'l')
		ft_printf(" -> %s", node->status.path_sym_link);
	ft_putchar('\n');
}
