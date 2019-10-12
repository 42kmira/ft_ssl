# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/29 20:34:09 by kmira             #+#    #+#              #
#    Updated: 2019/10/10 23:23:20 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

FLAGS = -Wall -Wextra -Werror

LIBRARY = libft/libft.a

INCLUDE = -I includes

MD5_SRCS = \
	main_md5

SHA256_SRCS = \
	main_sha256

SRCS = \
		debug \
		function_dispatch \
		main \
		output \
		parse_flags \
		utils

C_FILES = \
	$(addprefix srcs/md5/, $(addsuffix .c, $(MD5_SRCS))) \
	$(addprefix srcs/sha256/, $(addsuffix .c, $(SHA256_SRCS))) \
	$(addprefix srcs/, $(addsuffix .c, $(SRCS)))

OBJS = $(addsuffix .o, $(SRCS))

# gcc -o $(NAME) $(OBJS) $(LIBRARY)
all: $(NAME)

$(NAME): $(LIBRARY)
	@echo "Creating executable ft_ssl"
	@gcc $(FLAGS) $(LIBRARY) $(INCLUDE) $(C_FILES) -o $(NAME)

$(LIBRARY):
	make -C libft/

# $(OBJS):
# 	gcc -c $(FLAGS) $(INCLUDE) $(C_FILES)

clean:
	@echo "Removing all .o files"
	@make -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@echo "Fully cleaning program files"
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

quick: clean
	@rm -f $(NAME)
	make all
	@clear
	./ft_ssl md5 -s Testing
