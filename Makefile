NAME = cub3D

OBJ_PATH = tmp/

INC = inc/

SRC_PATH = src/

MLX_PATH = mlx_linux/

LIBFT_PATH = src/libft/

SRC = main.c parsing/parsing.c parsing/load_map.c \
		tools/tools.c tools/c3d_free.c tools/ft_free.c

SRC_PPREFIX = $(addprefix $(SRC_PATH),$(SRC))

OBJ = $(addprefix $(OBJ_PATH),$(SRC_PPREFIX:.c=.o))

CFLAGS = -I $(INC) -I $(LIBFT_PATH) -Wall -Wextra -Werror -g #-fsanitize=address

MLX_FLAGS = -Lmlx_linux  -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz


#############################################################################

# Regular Colors
BLACK := \033[0;30m
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m

# Reset
RESET := \033[0m

#############################################################################

all: tmp libraries $(NAME)

tmp:
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ)	libraries
	@gcc $(CFLAGS) $(OBJ) $(LIBFT_PATH)libft.a $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)cub3D compiled$(RESET)"

libraries:
	@echo "$(CYAN)Compiling libraries$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) bonus --no-print-directory
	@$(MAKE) -C $(MLX_PATH) --no-print-directory
	@echo "$(GREEN)Libraries compiled$(RESET)"
#MLX MAKE IS TMP SOLUION, WE DONT WANT TO COMPILE IT ALWAYS IF NO NEED.

$(OBJ_PATH)%.o:%.c Makefile $(LIBFT_PATH)libft.h $(INC)cub3D.h $(LIBFT_PATH)libft.a 
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) -Iminilibx-linux -O3  -c $< -o $@
	@echo "$(CYAN)Compiling cub3D:$(YELLOW) $@$(RESET)"

re: fclean all

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean --no-print-directory
	@echo "$(CYAN)Libft $(YELLOW)- $(RED)Objs deleted$(RESET)"
	@rm -rf $(OBJ_PATH)
	@echo "$(CYAN)cub3D $(YELLOW)- $(RED)Objs deleted$(RESET)"
	@$(MAKE) -C $(MLX_PATH) clean --no-print-directory
	@echo "$(CYAN)Minilibx $(RED)deleted$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean --no-print-directory
	@echo "$(CYAN)Libft $(RED)deleted$(RESET)"
	@rm -rf $(NAME)
	@echo "$(CYAN)cub3D $(RED)deleted$(RESET)"

.PHONY: all re clean fclean
