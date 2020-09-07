##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## All purpose Makefile by Tabis Lucas
##

########################### PIMP

COM_COLOR   	=	\033[0;34m
OBJ_COLOR   	= 	\033[0;36m
OK_COLOR 	= 	\033[0;32m
ERROR_COLOR 	= 	\033[0;31m
WARN_COLOR  	= 	\033[0;33m
NO_COLOR    	= 	\033[m

OK    		= 	"[OK]"
ERROR 		= 	"[ERROR]"
WARN  		= 	"[WARNING]"
COM   		= 	"Compiling"

########################### GENERIC

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	project

LIBFL	=	-Iinclude -Llib/my -lmy

WALLFL	=	-g -W -Wall -Wextra

########################### RULES


all:		comp_1 comp_2 cpy_biaries

comp_1:
		cd generator && $(MAKE)
		@echo -e "$(OK_COLOR)"$(OK) "$(COM_COLOR)""Generator compilation finished !" "$(NO_COLOR)"

comp_2:
		cd solver && $(MAKE)
		@echo -e "$(OK_COLOR)"$(OK) "$(COM_COLOR)""Solver compilation finished !" "$(NO_COLOR)"

cpy_biaries:
		cp solver/solver tournament

tests_run:
		cd tests/ && $(MAKE)

clean:
		@$(RM) -f $(OBJ)
		@find -type f -name '*~' -delete
		@find -type f -name '#*#' -delete
		@$(RM) -r -f *~ \#*\#
		@echo -e "$(OK_COLOR)"$(OK) "$(COM_COLOR)""Repository cleaned !" "$(NO_COLOR)"

fclean:         clean
		@$(RM) -f $(NAME)

re:		fclean all

.PHONY:		comp tests_run clean fclean re
