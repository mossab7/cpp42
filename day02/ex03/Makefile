SRCS = main.cpp Fixed.cpp Point.cpp
NAME = bsp
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf

all : $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
