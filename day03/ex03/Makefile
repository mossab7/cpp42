SRCS = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
NAME = DiamondTrap
FLAGS = -Wall -Wextra -Werror -Wshadow #-Wno-shadow
CC = c++ -std=c++98
RM = rm -rf
HEADER = ClapTrap.hpp FragTrap.hpp ScavTrap.hpp DiamondTrap.hpp

all : $(NAME)
$(NAME) $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
