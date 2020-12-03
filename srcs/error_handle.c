/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 08:37:47 by dthan             #+#    #+#             */
/*   Updated: 2020/07/08 21:22:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_err_permission_dinied(char *dirname, int *ret)
{
	ft_putstr_fd("ft_ls: cannot open directory '", STD_ERR);
	ft_putstr_fd(dirname, STD_ERR);
	ft_putstr_fd("': ", STD_ERR);
	ft_putstr_fd(strerror(EACCES), STD_ERR);
	ft_putchar_fd('\n', STD_ERR);
	*ret = MINOR_PROBLEMS;
}

void	ft_err_can_not_access(char *invalid_file_or_dir, int *ret)
{
	ft_putstr_fd("ft_ls: cannot access '", STD_ERR);
	ft_putstr_fd(invalid_file_or_dir, STD_ERR);
	ft_putstr_fd("': ", STD_ERR);
	ft_putstr_fd(strerror(ENOENT), STD_ERR);
	ft_putchar_fd('\n', STD_ERR);
	*ret = MINOR_PROBLEMS;
}

void	ft_err_invalid_option(char *invalid_option, int dashno)
{
	if (dashno == 1)
	{
		ft_putstr_fd("ft_ls: invalid option -- '", STD_ERR);
		ft_putchar_fd(*invalid_option, STD_ERR);
		ft_putstr_fd("'\nTry './ft_ls --help' for more information.\n", \
		STD_ERR);
	}
	else if (dashno == 2)
	{
		ft_putstr_fd("ft_ls: unrecognized option '--", STD_ERR);
		ft_putstr_fd(invalid_option, STD_ERR);
		ft_putstr_fd("'", STD_ERR);
		ft_putstr_fd("'\nTry './ft_ls --help' for more information.\n", \
		STD_ERR);
	}
	exit(SERIOUS_TROUBLE);
}

void	ft_err_malloc(void)
{
	strerror(ENOMEM);
	ft_putchar_fd('\n', STD_ERR);
	exit(SERIOUS_TROUBLE);
}

void	ft_err_can_not_read_link(char *path, int *ret)
{
	ft_putstr_fd("ft_ls: cannot read symbolic link '", STD_ERR);
	ft_putstr_fd(path, STD_ERR);
	ft_putstr_fd("': ", STD_ERR);
	ft_putstr_fd(strerror(EACCES), STD_ERR);
	ft_putchar_fd('\n', STD_ERR);
	*ret = MINOR_PROBLEMS;
}
