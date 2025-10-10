SRCS = main.cpp Bureaucrat.cpp Form.cpp
NAME = Form
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf
HEADER = Bureaucrat.hpp Form.hpp

all : $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :

fclean : clean
	$(RM) $(NAME)

re : fclean all
