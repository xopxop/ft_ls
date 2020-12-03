/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortlist_helper2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:43:22 by dthan             #+#    #+#             */
/*   Updated: 2020/07/08 20:46:57 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void	ft_print_short_list(t_table table, int width)
{
	int row2;
	int col2;

	row2 = 0;
	col2 = 0;
	while (row2 < table.row && table.table[row2][col2] != NULL)
	{
		while (col2 < table.col && table.table[row2][col2] != NULL)
		{
			ft_printf("%-*s", width, table.table[row2][col2]);
			col2++;
		}
		write(1, "\n", 1);
		row2++;
		col2 = 0;
	}
}
