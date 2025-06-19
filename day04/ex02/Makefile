SRCS = main.cpp Dog.cpp Cat.cpp IAnimal.cpp Brain.cpp
NAME = Brain
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf
HEADER = Dog.hpp Cat.hpp IAnimal.hpp Brain.hpp

all : $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
