NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
# -fsanitize=address
AR = ar -rcs
RM = rm -f

FILES =  main split utils sort instructions radix utils2 ft_memcpy

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)



re: clean all

.PHONY: all clean fclean re