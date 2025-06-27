SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
NAME = ScavTrap
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf
HEADER = ClapTrap.hpp ScavTrap.hpp

all : $(NAME)
$(NAME) $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
