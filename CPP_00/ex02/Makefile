NAME = Account
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Account.cpp tests.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

re: clean all
