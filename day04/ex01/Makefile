SRCS = main.cpp Dog.cpp Cat.cpp Animal.cpp Brain.cpp
NAME = Brain
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf
HEADER = Dog.hpp Cat.hpp Animal.hpp Brain.hpp

all : $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
