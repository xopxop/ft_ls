/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:31:22 by dthan             #+#    #+#             */
/*   Updated: 2020/03/27 15:15:44 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	get_options(char *input)
{
	if (ft_is_short_options(input[0], input[1]))
		return (get_short_options(input));
	return (get_long_option(input));
}

int	get_short_options(char *input)
{
	int options;

	options = 0;
	input++;
	while (*input)
	{
		if (*input == 'l')
			options |= LONG_LIST_FORMAT;
		else if (*input == 'R')
			options |= LIST_SUBDIR_RECUSIVELY;
		else if (*input == 'a')
			options |= LIST_HIDDEN;
		else if (*input == 'r')
			options |= REVERSE_ORDER;
		else if (*input == 't')
			options |= SORT_BY_NEWEST_FIRST;
		else
			ft_err_invalid_option(input, 1);
		input++;
	}
	return (options);
}

int	get_long_option(char *input)
{
	int option;

	option = 0;
	input = input + 2;
	if (!ft_strcmp(input, "all"))
		option |= LIST_HIDDEN;
	else if (!ft_strcmp(input, "reverse"))
		option |= REVERSE_ORDER;
	else if (!ft_strcmp(input, "recursive"))
		option |= LIST_SUBDIR_RECUSIVELY;
	else
		ft_err_invalid_option(input, 2);
	return (option);
}
