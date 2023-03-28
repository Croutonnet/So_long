CC = gcc -Wall -Werror -Wextra
RM = rm -f
NAME = so_long

FILE	=	main.c\
			map.c\
			killing.c\
			spawn.c\
			image.c\
			movement.c\
			verif_map.c\
			enemies.c\
			error.c\
			animation.c

LIBDIR = src/libft/

MLXDIR = src/MLX42/

LIBFT = libft.a

MLX = libmlx42.a

OFILE = $(FILE:.c=.o)

all: libft $(NAME)

$(NAME): $(OFILE)
		@echo "Compiling..."
		@$(CC) $(FILE) $(LIBDIR)$(LIBFT) $(MLXDIR)$(MLX) -I include -lglfw -L "/USERS/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

libft: mlx
	@$(MAKE) -C $(LIBDIR)

mlx:
	@$(MAKE) -C $(MLXDIR)

clean:
	@$(RM) $(OFILE)
	@$(RM) $(LIBDIR)*.o

fclean: clean
	@echo "Removing Executable and Object"
	@$(RM) $(NAME)
	@$(RM) $(LIBDIR)$(LIBFT)

run: all
	./so_long

mem: all
	leaks -atExit -- ./so_long

re:	fclean all