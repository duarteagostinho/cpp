NAME = RPN
SRC = main.cpp RPN.cpp
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

run: re 
	@echo "Testing subject example:"
	@echo './RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"'
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo './RPN "7 7 * 7 -"'
	@./$(NAME) "7 7 * 7 -"
	@echo './RPN "1 2 * 2 / 2 * 2 4 - +"'
	@./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@echo './RPN "(1 + 1)"'
	@./$(NAME) "(1 + 1)"
.PHONY: all clean fclean re
