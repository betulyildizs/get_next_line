NAME =	getnextline.a

FILES =	get_next_line.c \
		get_next_line_utils.c \

BONUS =	get_next_line_bonus.c \
		get_next_line_utils_bonus.c \

OBJS =	$(FILES:.c=.o)

BONUS_OBJS =	$(BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)

$(BONUS_OBJS): $(BONUS)
		ar rcs $(NAME) $(BONUS_OBJS)

clean:
		$(clean) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(fclean) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
