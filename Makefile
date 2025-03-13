SRCS= errors.c \
	  main.c \
	  event_handler.c \
	  init.c \
	  math_utils.c \
	  rendering.c \
	  str_utils.c \
	  validate_input.c \
	  burning_ship.c \

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
PINK = \033[38;2;245;166;221m
RESET = \033[0m
OBJS = $(SRCS:.c=.o)
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
INCLUDES = fractol.h

HEADER = "\n$(PINK)\
███████╗██████╗  █████╗  ██████╗████████╗ ██████╗ ██╗     \n\
██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██║     \n\
█████╗  ██████╔╝███████║██║        ██║   ██║   ██║██║     \n\
██╔══╝  ██╔══██╗██╔══██║██║        ██║   ██║   ██║██║     \n\
██║     ██║  ██║██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗\n\
╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝\n\
$(RESET)"
all: $(NAME)

$(NAME) : $(OBJS)
	@cd $(MLX_DIR) && $(MAKE) > /dev/null 2>/dev/null
	@$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)
	@echo $(HEADER)

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@cd $(MLX_DIR) && $(MAKE) clean > /dev/null
	@rm -f $(OBJS)
	@echo "cleaned"
fclean:
	@rm -f $(OBJS) $(NAME)
	@echo "fully clean"
re: fclean all

.PHONY: clean fclean all re
