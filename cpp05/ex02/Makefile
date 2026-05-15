NAME = AForm
SRC = Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp main.cpp
OBJS = $(SRC:.cpp=.o)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@c++ $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "COMPILATION SUCCESSFULL"

%.o:%.cpp
	@c++ $(CXXFLAGS) -c -g $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm *_shrubbery

fclean: clean
	@rm -rf $(NAME)

re: fclean all

run:
	@./$(NAME)

.PHONY: all clean fclean re
