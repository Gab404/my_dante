##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME    =    yes

$(NAME):
		make -C generator
		make -C solver

all:    $(NAME)

clean:
	rm -f generator/generator
	rm -f solver/solver

fclean: clean
	rm -f generator/src/*.o
	rm -f solver/src/*.o

re: fclean all

.PHONY: clean
	fclean
	re
