##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile
##

SRC	=	includes/my_putchar.c				\
		includes/my_put_nbr.c				\
		includes/my_putstr.c				\
		includes/my_strlen.c				\
		includes/my_unsigned_intlen.c		\
		includes/my_intlen.c				\
		includes/my_put_unsigned_nbr.c		\
		includes/mini_printf.c				\
		includes/error_message.c			\
		includes/is_flag.c					\
		includes/my_strlowcase.c			\
		includes/is_alpha.c					\
		includes/my_strcpy.c				\
		includes/get_files_names.c			\
		includes/my_str_to_word_array.c		\
		includes/is_alphanum.c				\
		includes/get_in_alpha_order.c		\
		includes/get_nbname.c				\
		includes/strchcmp.c					\
		includes/get_rev_alphorder.c		\
		flags/make_my_ls_l.c				\
		flags/make_my_ls_a.c				\
		flags/make_my_ls_r.c				\
		flags/make_my_ls_t.c				\
		my_ls.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

CFLAGS	=	-g

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

tests_run: all

re:	fclean all
