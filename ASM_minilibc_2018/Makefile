##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for assembly
##

SRC_DIR	= $(realpath src)
SRC_BON	= $(realpath bonus)

SRC	=	$(wildcard $(SRC_DIR)/*.asm)
SRCBON	=	$(wildcard $(SRC_BON)/*.asm)

OBJ	=	$(SRC:.asm=.o)
OBJBON	=	$(SRCBON:.asm=.o)

NAME	=	libasm.so

all:		$(NAME)

$(NAME):	$(OBJ)
		ld -shared -o $(NAME) $(OBJ)

%.o : %.asm
		nasm -f elf64 -o $@ $< -g # $@ : name of the file generated $< first prerequisit

tests_run:
		cd tests/ && $(MAKE)

bonus:	$(OBJ) $(OBJBON)
	      ld -shared -o $(NAME) $(OBJ) $(OBJBON) --no-builtin

$(NAME):	$(OBJ)
		ld -shared -o $(NAME) $(OBJ)

clean:
		@rm -f $(OBJ)
		@find -type f -name '*~' -delete
		@find -type f -name '#*#' -delete
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
