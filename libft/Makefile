# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 11:40:08 by kmira             #+#    #+#              #
#    Updated: 2019/02/24 15:44:00 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
FLAGS	= -Wall -Werror -Wextra -c
FUNCS	=	atoi \
			bzero \
			isalnum \
			isalpha \
			isascii \
			isdigit \
			isprint \
			memccpy \
			memchr \
			memcmp \
			memcpy \
			memmove \
			memset \
			strcat \
			strchr \
			strcmp \
			strcpy \
			strdup \
			strlcat \
			strlen \
			strncat \
			strncmp \
			strncpy \
			strnstr \
			strrchr \
			strstr \
			tolower \
			toupper \
			itoa \
			memalloc \
			memdel \
			putchar_fd \
			putchar \
			putendl_fd \
			putendl \
			putnbr_fd \
			putnbr \
			putstr_fd \
			putstr \
			strclr \
			strdel \
			strequ \
			strnequ \
			striter \
			striteri \
			strjoin \
			strmap \
			strmapi \
			strnew \
			strsplit \
			strsub \
			strtrim \
			lstadd \
			lstdel \
			lstdelone \
			lstiter \
			lstmap \
			lstnew \
			digit_amount \
			is_whitespace \
			fast_find \
			memcpy_foward \
			memcpy_at \
			str_go_to_end \
			min \
			islower \
			isupper

C_FILES	= $(addsuffix .c, $(addprefix ft_, $(FUNCS)))
OBJ		= $(addsuffix .o, $(addprefix ft_, $(FUNCS)))

.PHONY: clean fclean all re

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "	Creating .h file.."
	@ar rcs $(NAME) $(OBJ)

$(OBJ) :
	@echo "	Making OBJ Files..."
	@gcc $(FLAGS) $(C_FILES)

clean:
	@echo "	Removing only OBJ files..."
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "	Rmoving .h files..."
	@/bin/rm -f $(NAME)

re: fclean all
