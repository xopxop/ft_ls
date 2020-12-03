/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 01:32:17 by dthan             #+#    #+#             */
/*   Updated: 2020/03/25 01:32:18 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void	ft_init_struct_max(t_max *max)
{
	max->width_of_link = 0;
	max->width_of_user_name = 0;
	max->width_of_group_name = 0;
	max->width_of_size = 0;
}

void	initialize_struct(t_node *node)
{
	node->status.name = NULL;
	node->status.path = NULL;
	node->status.user_name = NULL;
	node->status.group_name = NULL;
	node->status.time = NULL;
	node->status.file_permission = NULL;
	node->status.type = '\0';
	node->status.path_sym_link = NULL;
	node->status.is_hidden = NO;
	node->status.allow_open = YES;
}
