/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 05:33:01 by dthan             #+#    #+#             */
/*   Updated: 2020/07/08 21:40:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_node	*ft_get_lchild(t_node *parent_dir, int *ret)
{
	t_node			*node;
	t_node			*lchild;
	DIR				*ptr_dir;
	struct dirent	*ptr_entry;

	lchild = NULL;
	ptr_dir = opendir(parent_dir->status.path);
	while ((ptr_entry = readdir(ptr_dir)))
	{
		if (!(node = (t_node*)malloc(sizeof(t_node))))
			ft_err_malloc();
		initialize_struct(node);
		ft_get_file_info(node, ptr_entry->d_name, parent_dir->status.path, ret);
		ft_push_node_to_lst(&lchild, node);
	}
	closedir(ptr_dir);
	return (lchild);
}

void	ft_recusion(t_node *parent, t_args *output)
{
	DIR				*ptr_dir;
	t_node			*child;

	while (parent)
	{
		if (parent->status.type == 'd' && parent->status.allow_open == YES && \
		!(!(output->options & LIST_HIDDEN) && parent->status.is_hidden == YES))
		{
			write(1, "\n", 1);
			if (!(ptr_dir = opendir(parent->status.path)))
				ft_err_permission_dinied(parent->status.name, &(output->ret));
			else
			{
				closedir(ptr_dir);
				child = ft_get_lchild(parent, &(output->ret));
				ft_sort(&child, output->options);
				ft_printf("%s:\n", parent->status.path);
				display(parent, NULL, child, *output);
				ft_recusion(child, output);
				free_lst(child);
			}
		}
		parent = parent->next;
	}
}

void	ft_ls(t_args *parent)
{
	t_node			*child;
	int				print_dname;
	t_node			*ptr;

	print_dname = (ft_lstcount(parent->dir) == 1 && parent->file == NULL && \
		!(parent->options & LIST_SUBDIR_RECUSIVELY)) ? NO : YES;
	if (parent->file)
	{
		display(NULL, parent->file, NULL, *parent);
		(parent->dir) ? ft_putchar('\n') : 0;
	}
	ptr = parent->dir;
	while (ptr)
	{
		(print_dname == YES) ? ft_printf("%s:\n", ptr->status.path) : 0;
		child = ft_get_lchild(ptr, &(parent->ret));
		ft_sort(&child, parent->options);
		display(ptr, NULL, child, *parent);
		(parent->options & LIST_SUBDIR_RECUSIVELY) ? \
			ft_recusion(child, parent) : 0;
		free_lst(child);
		ptr = ptr->next;
		(ptr != NULL) ? ft_putchar('\n') : 0;
	}
}

void	ft_get_arguments(char **input, t_args *output)
{
	int		arg_nbr;

	arg_nbr = 1;
	while (input[arg_nbr])
	{
		if (ft_isoptions(input[arg_nbr][0]))
			output->options |= get_options(input[arg_nbr]);
		else if (ft_isfile(input[arg_nbr], &(output->ret)))
			ft_split_input(input[arg_nbr], output);
		arg_nbr++;
	}
	if (output->dir == NULL && output->file == NULL && output->ret == 0)
		ft_split_input(".", output);
	ft_sort_alphabet(output->file);
	ft_sort_alphabet(output->dir);
}

int		main(int ac, char **av)
{
	t_args	output;

	output.ret = 0;
	output.options = 0;
	output.file = NULL;
	output.dir = NULL;
	(void)ac;
	ft_get_arguments(av, &output);
	ft_ls(&output);
	ft_free_larg(&output);
	return (output.ret);
}
