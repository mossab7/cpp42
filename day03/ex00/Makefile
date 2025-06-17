SRCS = main.cpp ClapTrap.cpp
NAME = ClapTrap
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf
HEADER = ClapTrap.hpp

all : $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
