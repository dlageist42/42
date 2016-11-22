NAME = ft_select

SRC = main.c setup_term.c select_init.c select_update.c \
	select_render.c select_quit.c handle_inputs.c term_go_home.c \
	term_clear.c term_clear_down.c term_goto_relative.c \
	select_render_item.c term_mode_rv.c term_mode_off.c term_underline.c \
	select_move.c term_show_cursor.c select_toggle.c term.c \
	select_render_bar.c select_del.c draw_bar.c search_render.c \
	search_add.c search_remove.c search_find.c search_reset.c \
	setup_signals.c

INCLUDES = -Iincludes -Ilib/libft/includes
LIB_FLAGS = -Llib/libft -lft -lncurses
FLAGS = -Wextra -Werror -Wall $(INCLUDES)

OBJ_DIR = obj
SRC_DIR = src

VPATH = $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@make -C lib/libft
	@gcc -Ofast $(OBJS) $(FLAGS) $(LIB_FLAGS) -o $(NAME)
	@echo "\n✅  FT_SELECT BUILT !"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@gcc $(FLAGS) -c $< -o $@
	@echo "$(NAME) => \033[33;32m$@\033[33;0m"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	@make -C lib/libft fclean

re: fclean all
