##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## All purpose Makefile by Tabis Lucas
##

all:	tests_run

tests_run:
		cd tests/ && $(MAKE)

clean:
		@$(RM) -f $(OBJ)
		@find -type f -name '*~' -delete
		@find -type f -name '#*#' -delete
		@find -type f -name '*.o' -delete
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete
		@$(RM) -r -f *~ \#*\#

fclean:         clean
		@$(RM) -f $(NAME)

re:		fclean all

.PHONY:	tests_run clean fclean re
