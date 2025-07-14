SRCS = main.cpp Bureaucrat.cpp
NAME = Bureaucrat
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf
HEADER = Bureaucrat.hpp

all : $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
