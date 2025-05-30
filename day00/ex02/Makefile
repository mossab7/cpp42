SRCS = tests.cpp Account.cpp
NAME = Account
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf
HEADERS = Account.hpp

all : $(SRCS) $(HEADERS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
