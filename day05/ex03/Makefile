SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp\
 RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
NAME = AForm
FLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98
RM = rm -rf
HEADER = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp\
 RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

all : $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :

fclean : clean
	$(RM) $(NAME)

re : fclean all
