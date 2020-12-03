# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 04:50:06 by dthan             #+#    #+#              #
#    Updated: 2020/07/08 20:45:27 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

INCLUDES = includes/

CFLAGS = -Wall -Wextra -Werror -g

SRCS_CODES = srcs/main.c srcs/options.c srcs/error_handle.c \
srcs/free.c srcs/display.c srcs/sort.c \
srcs/utility/parser.c srcs/utility/compaser.c srcs/utility/longlist_helper.c \
srcs/utility/shortlist_helper.c srcs/utility/shortlist_helper2.c \
srcs/utility/initializer.c \
srcs/utility/info_collecter.c srcs/utility/info_collecter2.c \
srcs/utility/tools.c srcs/utility/sort_helper.c

SRCS_OBJ = main.o options.o error_handle.o free.o display.o\
sort.o \
parser.o compaser.o longlist_helper.o shortlist_helper.o shortlist_helper2.o \
initializer.o info_collecter.o info_collecter2.o tools.o sort_helper.o

all: $(NAME)

$(NAME):
	@make -s -C libft/ fclean && make -s -C libft/
	@echo "\033[32mCreated My Library\033[0m"
	@gcc $(CFLAGS) -I$(INCLUDES) -c $(SRCS_CODES) 
	@gcc $(CFLAGS) $(SRCS_OBJ) libft/libft.a -o $(NAME)
	@echo "\033[32mCreated FT_LS Binary\033[0m"

clean:
	@make clean -s -C libft/
	@rm -f $(SRCS_OBJ)
	@echo "\033[32mRemoved FT_LS Object files\033[0m"

fclean: clean
	@make fclean -s -C libft/
	@rm -f $(NAME)
	@echo "\033[32mRemoved FT_LS Binary\033[0m"

re: fclean all
