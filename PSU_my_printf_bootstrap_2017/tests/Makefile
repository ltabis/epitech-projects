##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for the bootstrap of my_printf
##

SRC_DIR=	$(realpath..)

SRC=		$(SRC_DIR)/XXXX.c \
		$(SRC_DIR)/YYYY.c

SRC_UT_DIR=	$(realpath.)

SRC_UT=		$(SRC_UT_DIR)/tests_XXXX.c \
		$(SRC_UT_DIR)/tests_YYYY.c

OBJ=		$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=		-Wall -Wextra --coverage

LDFLAGS=	-lcriterion -lgcov

NAME=		units

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:		fclean all


