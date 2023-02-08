NAME = so_long

SRCS =	get_next_line/get_next_line.c 	  \
      	get_next_line/get_next_line_utils.c \
	  	main.c								\
		so_long_utils.c						\
		parsing.c							\

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
	rm -f $(NAME)

re: fclean all EXEC