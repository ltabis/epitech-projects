##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC	=	my_printf.c		\
		my_printf_flags.c	\
		my_printf_flags_bis.c	\
		my_printf_flags_bonus.c	\
		src/my_putchar.c	\
		src/my_put_nbr.c	\
		src/my_putstr.c		\
		src/my_revstr.c		\
		src/my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(NAME) $(OBJ)

$(NAME):
		ar rc $(NAME) $(OBJ)		

clean:	
		rm -f $(OBJ)
		rm -f *.gcno
		rm -f *.gcda

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
