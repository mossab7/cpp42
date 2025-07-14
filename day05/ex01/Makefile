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
	$(RM) $(NAME)

fclean : clean

re : fclean all
