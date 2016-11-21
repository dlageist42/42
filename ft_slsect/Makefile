NAME 		= ft_select

DEBUG 		= no
ifeq ($(DEBUG),no)
    FLAGS	= -Wall -Werror -Wextra
else
    FLAGS	= -g3
endif
SRC 		= 	main.c error.c params.c infos.c term.c signal.c select.c cap.c \
				draw.c input.c render_bar.c \
				lst_new.c lst_push.c lst_get.c lst_free.c lst_move.c lst_del.c \
				lst_search.c \

OBJ 		= $(SRC:.c=.o)
LIBFLAGS 	= -L./libft/ -lft
SRCDIR  	= ./src/
OBJDIR  	= ./obj/
INCDIRLIB	= ./libft/includes/
INCDIR		= ./includes/
SRCS    	= $(addprefix $(SRCDIR), $(SRC))
OBJS    	= $(addprefix $(OBJDIR), $(OBJ))

.SILENT:

all : 		$(NAME)

$(NAME) :
ifeq ($(DEBUG),yes)
		echo "\\033[1;31mDEBUG COMPILATION.. (no flags except -g)\\033[0;39m"
else
		echo "\\033[1;31mCompilation with -Wall -Wextra -Werror...\\033[0;39m"
endif
		echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
			make -C libft/
			gcc $(FLAGS) -c  $(SRCS) -I $(INCDIR) -I $(INCDIRLIB)
			echo "compiling $(NAME)..."
			mkdir -p $(OBJDIR)
			mv $(OBJ) $(OBJDIR)
			gcc $(FLAGS) -o $(NAME)  $(OBJS) -lncurses  $(LIBFLAGS)
			echo "✅  $(NAME) has been created !"

.PHONY: 	clean fclean re

clean :
			make -C ./libft/ clean
			rm -rf $(OBJS)
			rm -rf $(OBJDIR)
			echo "objects files has been removed !"

fclean :	clean
			make -C ./libft/ fclean
			rm -rf $(NAME)
			echo "$(NAME) has been removed !"

re		: 	fclean all


git :
			git add .
			echo "Enter Your Commit : "
			read root_path ; git commit -m "$$root_path"
			git push
