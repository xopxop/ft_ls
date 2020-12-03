/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compaser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 01:03:38 by dthan             #+#    #+#             */
/*   Updated: 2020/05/31 17:28:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

int	ft_cmp_time(t_node *file1, t_node *file2)
{
	return (file1->status.stats.st_mtime < file2->status.stats.st_mtime);
}

int	ft_cmp_name(t_stat file1, t_stat file2)
{
	int check1;
	int check2;

	check1 = 0;
	check2 = 0;
	if (file1.allow_open && file2.allow_open)
	{
		if (file1.is_hidden)
			file1.name++;
		if (file2.is_hidden)
			file2.name++;
		check1 = (ft_isupper(file1.name[0])) ? 32 : 0;
		check2 = (ft_isupper(file2.name[0])) ? 32 : 0;
	}
	return (ft_strcmp(file1.name, file2.name) + check1 - check2 > 0);
}
