/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_collecter2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 01:50:21 by dthan             #+#    #+#             */
/*   Updated: 2020/07/08 02:27:37 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

char	*ft_get_path(char *filename, char *path)
{
	char *path_str;

	if (path == NULL)
		path_str = ft_strdup(filename);
	else if (!ft_strcmp("/", path))
		path_str = ft_strjoin("/", filename);
	else
		path_str = ft_strjoin_and_free_string1(ft_strjoin(path, "/"), filename);
	return (path_str);
}

void	ft_get_file_info(t_node *node, char *filename, char *path, int *ret)
{
	struct stat	filestat;

	node->status.name = ft_strdup(filename);
	node->status.path = ft_get_path(node->status.name, path);
	lstat(node->status.path, &filestat);
	node->status.type = ft_get_data_type(filestat.st_mode);
	(node->status.type == 'l') ? node->status.path_sym_link = \
		ft_get_path_sym_link(node->status.path, ret) : 0;
	node->status.file_permission = ft_get_file_permission(filestat.st_mode);
	node->status.user_name = ft_get_user_name(filestat.st_uid);
	node->status.group_name = ft_get_group_name(filestat.st_gid);
	node->status.time = ft_get_time(filestat.st_mtime);
	node->status.stats = filestat;
	node->status.min_of = ft_get_min(node);
	node->status.is_hidden = (node->status.name[0] == '.') ? YES : NO;
	node->status.allow_open = (!(ft_strcmp(".", node->status.name)) || \
		!(ft_strcmp("..", node->status.name))) ? NO : YES;
	node->next = NULL;
}

char	*ft_get_path_sym_link(char *pathname, int *ret)
{
	char	*symlink;
	char	buf[50];
	ssize_t	len;

	len = readlink(pathname, buf, sizeof(buf) - 1);
	if (len != -1)
	{
		buf[len] = '\0';
		if (!(symlink = ft_strdup(buf)))
			ft_err_malloc();
		return (symlink);
	}
	ft_err_can_not_read_link(pathname, ret);
	return (NULL);
}

t_min	ft_get_min(t_node *node)
{
	t_min min;

	min.width_of_link = ft_numlen(node->status.stats.st_nlink);
	min.width_of_user_name = ft_strlen(node->status.user_name);
	min.width_of_group_name = ft_strlen(node->status.group_name);
	min.width_of_size = ft_numlen(node->status.stats.st_size);
	return (min);
}
