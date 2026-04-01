NAME = fixed
SRC = Fixed.cpp main.cpp
OBJS = $(SRC:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

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

.PHONY: all clean fclean re

