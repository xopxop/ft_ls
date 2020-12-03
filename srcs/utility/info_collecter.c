/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_collecter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:34:24 by dthan             #+#    #+#             */
/*   Updated: 2020/03/15 15:34:25 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_get_user_name(uid_t id)
{
	struct passwd *pwd;

	if (!(pwd = getpwuid(id)))
		return (ft_itoa(id));
	return (ft_strdup(pwd->pw_name));
}

char	*ft_get_group_name(gid_t id)
{
	struct group *grp;

	if (!(grp = getgrgid(id)))
		return (ft_itoa(id));
	return (ft_strdup(grp->gr_name));
}

char	*ft_get_time(time_t time_file)
{
	char	*str;
	time_t	now;
	char	*t;

	now = time(&now);
	str = ft_strnew(12);
	t = ctime(&time_file);
	ft_strncpy(str, t + 4, 7);
	if (time_file > (now + 15778463) || time_file < (now - 15778463))
		ft_strncpy(str + 7, t + 19, 5);
	else
		ft_strncpy(str + 7, t + 11, 5);
	return (str);
}

char	*ft_get_file_permission(mode_t mode)
{
	char *str;

	str = ft_strnew(9);
	str[0] = (mode & S_IRUSR) ? 'r' : '-';
	str[1] = (mode & S_IWUSR) ? 'w' : '-';
	str[2] = (mode & S_IXUSR) ? 'x' : '-';
	str[3] = (mode & S_IRGRP) ? 'r' : '-';
	str[4] = (mode & S_IWGRP) ? 'w' : '-';
	str[5] = (mode & S_IXGRP) ? 'x' : '-';
	str[6] = (mode & S_IROTH) ? 'r' : '-';
	str[7] = (mode & S_IWOTH) ? 'w' : '-';
	str[8] = (mode & S_IXOTH) ? 'x' : '-';
	return (str);
}

char	ft_get_data_type(mode_t mode)
{
	if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISFIFO(mode))
		return ('p');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISREG(mode))
		return ('-');
	return ('?');
}
