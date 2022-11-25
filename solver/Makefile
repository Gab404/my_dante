##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC =	./src/basic_functions.c \
		./src/solver.c \
		./src/lib.c \
		./src/create_maze_with_way.c \
		./src/check_direction.c \
		./src/replace_map.c \

OBJ    =    $(SRC:.c=.o)

NAME   =    solver

CFLAGS += -Wall -Wextra -ggdb3

CPPFLAGS	+=	-I./includes

all:    $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) -g3 $(OBJ)

clean:
	@$(RM) lib/my/*.o
	@$(RM) lib/my/*~
	@$(RM) src/*.o
	@$(RM) src/*~

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(U_T)
	@$(RM) vgcore*
	@$(RM) *.gcda
	@$(RM) *.gcno
	@$(RM) a.out
	@$(RM) *.o
	@$(RM) *~

re: fclean all

.PHONY: all clean fclean re
