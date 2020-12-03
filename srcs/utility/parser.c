/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 09:28:16 by dthan             #+#    #+#             */
/*   Updated: 2020/07/09 19:48:12 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

int	ft_isoptions(char chr)
{
	return (chr == '-');
}

int	ft_is_short_options(char chr1, char chr2)
{
	return ((chr1 == '-' && chr2 != '-'));
}

int	ft_is_long_option(char chr1, char chr2)
{
	return ((chr1 == '-' && chr2 == '-'));
}

int	ft_isfile(char *dir_name, int *ret)
{
	struct stat		filestat;
	DIR				*ptr_dir;

	if ((lstat(dir_name, &filestat)) == -1)
	{
		ft_err_can_not_access(dir_name, ret);
		return (NO);
	}
	if (!(ptr_dir = opendir(dir_name)))
	{
		ft_err_permission_dinied(dir_name, ret);
		return (NO);
	}
	closedir(ptr_dir);
	return (YES);
}
