# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lde-la-h <lde-la-h@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/14 14:36:58 by lde-la-h      #+#    #+#                  #
#    Updated: 2021/12/14 16:06:27 by avan-ber      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = coldrace

CFLAGS = -Wall -Werror -Wextra -g

OBJ_DIR = objs
SRC_DIR = src

_OBJ_FILES =	main \
				input/input \
				utils/constructors \
				utils/utils \
				avl

OBJ_FILES = $(addsuffix .o, $(addprefix $(OBJ_DIR)/,$(_OBJ_FILES)))

COLDRACE_LOC = includes

#includes
INCLUDES	=	-I $(COLDRACE_LOC) 

#colors
RESET =		\x1b[0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_FILES) $(INCLUDES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c includes/coldrace.h
	@mkdir -p $(OBJ_DIR)/$(dir $*)
	$(CC) -c $(CFLAGS) $(INCLUDES) -I . $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
