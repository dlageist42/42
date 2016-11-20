NAME = fdf
CC = gcc
RM = rm -f
CFLAGS = -lmlx -framework OpenGL -framework Appkit
OBJ = $(SRC:.c)
SRC = sources/dparse.c\
		sources/main.c\
		sources/npparse.c\
		sources/parse.c\
		sources/parseho.c\
		sources/parseve.c\
		sources/posho.c\
		sources/posve.c\
		sources/decla.c

HEAD = ./includes

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $@ $< $(SRC) -I $(HEAD)  $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
