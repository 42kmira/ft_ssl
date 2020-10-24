# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/29 20:34:09 by kmira             #+#    #+#              #
#    Updated: 2019/10/18 15:04:47 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

FLAGS = -Wall -Wextra -Werror

LIBRARY = libft/libft.a

INCLUDE = -I includes

MD5_SRCS = \
	main_md5 \
	md5_utils

SHA256_SRCS = \
	main_sha256 \
	sha256_utils

SHA224_SRCS = \
	main_sha224 \
	sha224_utils

SHA512_SRCS = \
	main_sha512 \
	sha512_utils

SHA384_SRCS = \
	main_sha384 \
	sha384_utils

SRCS = \
		debug \
		function_dispatch \
		io_input_reading \
		io_output \
		main \
		parse_files \
		parse_flags \
		utils

C_FILES = \
	$(addprefix srcs/md5/, $(addsuffix .c, $(MD5_SRCS))) \
	$(addprefix srcs/sha256/, $(addsuffix .c, $(SHA256_SRCS))) \
	$(addprefix srcs/sha224/, $(addsuffix .c, $(SHA224_SRCS))) \
	$(addprefix srcs/sha512/, $(addsuffix .c, $(SHA512_SRCS))) \
	$(addprefix srcs/sha384/, $(addsuffix .c, $(SHA384_SRCS))) \
	$(addprefix srcs/, $(addsuffix .c, $(SRCS)))

OBJS = $(addsuffix .o, $(SRCS))

# gcc -o $(NAME) $(OBJS) $(LIBRARY)
all: $(NAME)

$(NAME): $(LIBRARY)
	@echo "Creating executable ft_ssl"
	@gcc $(FLAGS) $(LIBRARY) $(INCLUDE) $(C_FILES) -o $(NAME)

$(LIBRARY):
	make -C libft/

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
