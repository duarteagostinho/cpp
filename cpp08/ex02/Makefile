NAME = MutantStack
SRC = main.cpp
OBJS = $(SRC:.cpp=.o)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -Iinc/

all: $(NAME)

$(NAME): $(OBJS)
	@c++ $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "COMPILATION SUCCESSFULL"

%.o:%.cpp
	@c++ $(CXXFLAGS) -c -g $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

run:
	@make re
	@./$(NAME)

.PHONY: all clean fclean re
