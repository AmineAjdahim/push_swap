NAME = push_swap
LIBFT =	Libft/libft.a
CC = gcc
INC = -I includes/
SRCS =	main.c operations1.c operations2.c check1.c check2.c three_five.c static.c
FLAGS = -Wall -Wextra -Werror -g -lreadline
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