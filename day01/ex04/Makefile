SRCS =  main.cpp
NAME = replace
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf

all : $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
