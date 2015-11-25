NAME = libft.a

SOURCES = ft_putchar.c ft_putstr.c ft_putnbr.c ft_isalpha.c \
		ft_isdigit.c

HEADERS = includes/libft.h

OBJECTS = $(subst .c,.o,$(SOURCES))

WFLAGS = -Wall -Werror -Wextra -I includes

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "Making Library : \033[5m\033[31m DONE !\033[0m"

$(OBJECTS): $(SOURCES) $(HEADERS)
	@gcc $(WFLAGS) -c $(SOURCES)

clean :
	@rm -f $(OBJECTS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
