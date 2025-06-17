SRCS = main.cpp ClapTrap.cpp FragTrap.cpp
NAME = FragTrap
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf
HEADER = ClapTrap.hpp FragTrap.hpp

all : $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
