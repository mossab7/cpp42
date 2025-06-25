SRCS = megaphone.cpp
NAME = megaphone
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
