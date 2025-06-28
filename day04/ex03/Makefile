SRCS = main.cpp Cure.cpp Ice.cpp AMateria.cpp Character.cpp MateriaSource.cpp
NAME = MateriaSource
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98 -g
RM = rm -rf
HEADER = Cure.hpp Ice.hpp AMateria.hpp Character.hpp MateriaSource.hpp AMateria.hpp ICharacter.hpp

all : $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
