/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:23:59 by dthan             #+#    #+#             */
/*   Updated: 2020/06/11 03:05:44 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	free_lst(t_node *node)
{
	t_node *ptr;

	while (node)
	{
		ptr = node;
		node = node->next;
		free(ptr->status.name);
		free(ptr->status.path);
		free(ptr->status.user_name);
		free(ptr->status.group_name);
		free(ptr->status.time);
		free(ptr->status.file_permission);
		if (ptr->status.path_sym_link)
			free(ptr->status.path_sym_link);
		free(ptr);
	}
}

void	ft_free_larg(t_args *input_file)
{
	if (input_file->file != NULL)
		free_lst(input_file->file);
	if (input_file->dir != NULL)
		free_lst(input_file->dir);
}

void	ft_free_table(t_table table)
{
	int row;

	row = -1;
	while (++row < table.row)
		free(table.table[row]);
	free(table.table);
}
