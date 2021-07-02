NAME = push_swap
LIBFT =	Libft/libft.a
CC = gcc
INC = -I includes/
SRCS =	main.c 
FLAGS = -Wall -Wextra -Werror -g -lreadline
# FLAGS =
OBJS = $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(INC) $(SRCS) -o $(NAME) $(LIBFT)
$(LIBFT):
	@make -C ./Libft
clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
re : fclean $(NAME)