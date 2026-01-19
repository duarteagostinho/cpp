NAME = BraiiiiiiinnnzzzZ
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRC:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@c++ $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "COMPILATION SUCCESSFULL"

%.o: %.cpp
	@c++ $(CPPFLAGS) -c -g $< -o $@

clean:
	@rm -rf $(OBJS)
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
