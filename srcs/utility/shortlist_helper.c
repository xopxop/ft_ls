/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortlist_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 01:20:19 by dthan             #+#    #+#             */
/*   Updated: 2020/07/08 20:45:43 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

int		ft_get_terminal_width(void)
{
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int		ft_get_max_file_name(t_node *node, int options)
{
	int max;

	max = 0;
	while (node)
	{
		if (!(options & LIST_HIDDEN) && node->status.is_hidden == YES)
			;
		else if (max < (int)ft_strlen(node->status.name))
			max = ft_strlen(node->status.name);
		node = node->next;
	}
	return (max);
}

int		ft_get_list_size(t_node *node, int options)
{
	int ct;

	ct = 0;
	while (node)
	{
		if (!(options & LIST_HIDDEN) && node->status.is_hidden == YES)
			;
		else
			ct++;
		node = node->next;
	}
	return (ct);
}

char	***ft_creat_table(int row, int col)
{
	char	***table;
	int		i;
	int		j;

	i = 0;
	table = (char***)ft_memalloc(sizeof(char**) * row);
	while (i < row)
	{
		table[i] = (char**)malloc(sizeof(char*) * col);
		j = 0;
		while (j < col)
		{
			table[i][j] = NULL;
			j++;
		}
		i++;
	}
	return (table);
}

void	ft_putlist_into_table(t_table table, t_node *node, int options)
{
	int row2;
	int col2;

	col2 = 0;
	while (col2 < table.col && node != NULL)
	{
		row2 = 0;
		while (row2 < table.row && node != NULL)
		{
			if (!(options & LIST_HIDDEN) && node->status.is_hidden == YES)
			{
				node = node->next;
				continue;
			}
			table.table[row2][col2] = node->status.name;
			node = node->next;
			row2++;
		}
		col2++;
	}
}
