NAME = so_long

SRCS =	get_next_line/get_next_line.c 	  \
      	get_next_line/get_next_line_utils.c \
	  	main.c								\
		so_long_utils.c						\
		parsing.c							\
		parsing_hlpr.c						\
		ft_printf/ft_format.c			\
		ft_printf/ft_printhex.c			\
		ft_printf/ft_printf.c			\
		ft_printf/ft_printpointer.c		\
		ft_printf/ft_printunsigned.c		\
		ft_printf/ft_putchar.c			\
		ft_printf/ft_putnbr.c			\
		ft_printf/ft_putstr.c


OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g3 #-fsanitize=address

EXEC = so_long

all : $(NAME)

$(NAME): $(OBJS)
	(cd mlx && make)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(EXEC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: fclean all 