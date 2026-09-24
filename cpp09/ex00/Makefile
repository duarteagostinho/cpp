NAME = btc
SRC = main.cpp BitcoinExchange.cpp
OBJS = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "COMPILATION SUCCESSFULL"

%.o:%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

run:
	@./$(NAME) input.txt

.PHONY: all clean fclean re
