CC=cc
NAME = cub3D
SRCPATH = src/
LIBFT = libft/libft.a
LIBMLX	= MLX42
SRCS = main.c \
		parsing/have_map.c \
		parsing/parsing_map.c \
		parsing/parsing_color.c \
		parsing/parsing_arg_and_fd.c \
		parsing/parsing_map_utils.c \
		parsing/parsing_map_utils2.c \
		parsing/parsing_pos_player.c \
		parsing/parsing_texture.c \
		parsing/init_all_of_value.c \
		parsing/free_and_error.c \
		parsing/get_next_line/get_next_line.c \
		parsing/get_next_line/get_next_line_utils.c \
		setup/init.c \
		exec/map.c \
		exec/hook.c \
		exec/utils.c \
		exec/raycasting.c \
		exec/free.c
SRCSINC = $(addprefix $(SRCPATH), $(SRCS))
HEADERS = -I includes -I $(LIBMLX)/include
OBJS = $(SRCSINC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = $(LIBMLX)/build/libmlx42.a $(LIBFT) -ldl -lglfw -pthread -lm 

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) $(LIBFT)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make --no-print-directory -C $(LIBMLX)/build -j4
	$(CC) $(OBJS) $(LFLAGS) $(HEADERS) -o $(NAME)

$(LIBFT):
	@make -j8 -C libft/ all

fclean: clean
	rm -f $(NAME)
	rm -rf $(LIBMLX)/build
	@make -C libft/ clean

clean:
	rm -f $(OBJS)
	@make -C libft/ clean

re: fclean all

.PHONY: all fclean clean re
