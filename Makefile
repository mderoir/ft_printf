LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS    = ./ft_printf.c \
                ./sources/type_build.c \
            	./sources/flag_handler.c \
            	./sources/input_parser.c \
            	./sources/p_adress.c	\
				./sources/p_char.c	\
				./sources/p_hexa.c	\
				./sources/p_int.c	\
				./sources/p_percent.c	\
				./sources/p_precision.c	\
				./sources/p_string.c	\
				./sources/p_unsint.c	\
				./sources/p_width.c	\


CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes/

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

.PHONY:     all clean fclean re