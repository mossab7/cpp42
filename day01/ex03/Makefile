SRCS =  main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
NAME = violence
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf
HEADER = HumanA.hpp HumanB.hpp Weapon.hpp

all : $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
