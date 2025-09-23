NAME= Account
SRC= Account.cpp tests.cpp
OBJS= $(SRC:.cpp=.o)
FLAGS= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)
%.o: %.cpp
	c++ $(FLAGS) -c -g $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: re all
	./PhoneBook
