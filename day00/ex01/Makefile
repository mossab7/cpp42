SRCS = PhoneBook.cpp main.cpp Contact.cpp
NAME = phonebook
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf
HEADERS = Contact.hpp PhoneBook.hpp

all : $(SRCS) $(HEADERS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean : clean

re : fclean all
