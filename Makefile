NAME = cube3D

OBJ_PATH = tmp/

INC = inc/

SRC_PATH = src/

#TMP_DIR = $(CURDIR)/tmp/

LIBFT_PATH = libft/

SRC = main.c

SRC_PPREFIX = $(addprefix $(SRC_PATH),$(SRC))

OBJ = $(addprefix $(OBJ_PATH),$(SRC_PPREFIX:.c=.o))

CFLAGS = -I ./inc -I ./libft -Wall -Wextra -Werror -g -fsanitize=address


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