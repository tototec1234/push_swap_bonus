NAME = checker

SRC_DIR = src
SRCS = $(SRC_DIR)/checker.c \
	   $(SRC_DIR)/checker_utils.c \
	   $(SRC_DIR)/stack_operations.c \
	   $(SRC_DIR)/instructions_swap.c \
	   $(SRC_DIR)/instructions_push.c \
	   $(SRC_DIR)/instructions_rotate.c \
	   $(SRC_DIR)/instructions_reverse_rotate.c \
	   $(SRC_DIR)/parse_utils.c

OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iinc -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus

