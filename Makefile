NAME = fdf

SRCNAME	=   main.c \
			reader.c \
			draw.c \
			init.c	\
			keyboard.c	\
			rotation.c	\
			hex_to_digit.c\
			free.c \
			check.c

SRC    = $(addprefix src/, $(SRCNAME))
OBJECT = $(SRC:.c=.o)
FLAGS  = -Wall -Wextra -Werror
HDIR   = include
LIBFT = libft/libft.a

all: lib $(NAME)

$(NAME):$(OBJECT)
	gcc $(OBJECT) $(LIBFT) -l mlx -framework OpenGL -framework AppKit -o $(NAME)

lib:
	make -C libft

%.o: %.c
	gcc $(FLAGS) -o $@ -c $< -I $(HDIR)

clean:
	rm -f $(OBJECT)
	make clean -C libft
	rm -f "*.swp"

fclean: clean
	make clean -C libft
	rm -f $(NAME)

re: fclean all