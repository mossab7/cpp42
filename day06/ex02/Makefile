CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp IdentifyRealType.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = identify_real_type

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
