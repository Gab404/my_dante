##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC =	./src/generator.c \
		./src/gest_error.c \
		./src/lib.c \
		./src/lib2.c \
		./src/create_maze.c \
		./src/create_grid.c \

OBJ    =    $(SRC:.c=.o)

NAME   =    generator

CFLAGS += -Wall -Wextra

CPPFLAGS	+=	-I./includes

all:    $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

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
