# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/29 20:34:09 by kmira             #+#    #+#              #
#    Updated: 2019/10/03 00:02:17 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

LIBRARY = libft/libft.a

INCLUDE = -I includes

SRCS = \
		function_dispatch \
		main \
		md5 \
		parse_flags

C_FILES = $(addprefix srcs/, $(addsuffix .c, $(SRCS)))
OBJS = $(addsuffix .o, $(SRCS))

all: $(NAME)

$(NAME): $(LIBRARY) $(OBJS)
	@echo "Creating executable ft_ssl"
	gcc -o $(NAME) $(OBJS) $(LIBRARY)

$(LIBRARY):
	make -C libft/

$(OBJS):
	gcc -c $(FLAGS) $(INCLUDE) $(C_FILES)

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
	./$(NAME)
