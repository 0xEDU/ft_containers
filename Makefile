VECTOR_NAME = vector
VECTOR_ITERATOR_NAME = vector_iterator

PATH_VECTOR_TESTS = ./tests/vector/
PATH_CONTAINERS = ./includes/
PATH_TESTS = ./tests/
PATH_OBJS = ./objects/
PATH_BINARY = ./bin/

VECTOR_TESTS =	vector_tests.cpp
VECTOR_OBJS = $(patsubst %.cpp,$(PATH_OBJS)%.o,$(VECTOR_TESTS))

VECTOR_ITERATOR_TESTS =	vector_iterator_tests.cpp
VECTOR_ITERATOR_OBJS = $(patsubst %.cpp,$(PATH_OBJS)%.o,$(VECTOR_ITERATOR_TESTS))

INCLUDE_CONTAINERS = -I $(PATH_CONTAINERS)
INCLUDE_TESTS = -I $(PATH_TESTS)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

all: $(VECTOR_NAME) $(VECTOR_ITERATOR_NAME)

vector-run: fclean $(VECTOR_NAME)
	@./$(VECTOR_NAME)
	@rm -rf $(VECTOR_NAME)

vvector-run: fclean $(VECTOR_NAME)
	@valgrind ./$(VECTOR_NAME)
	@rm -rf $(VECTOR_NAME)

vector-iterator-run: fclean $(VECTOR_ITERATOR_NAME)
	@./$(VECTOR_ITERATOR_NAME)
	@rm -rf $(VECTOR_NAME)

$(VECTOR_NAME): $(VECTOR_OBJS)
	@if [ ! -d $(PATH_BINARY) ]; then \
		mkdir -p $(PATH_BINARY); \
	fi
	@c++ $(CXXFLAGS) $(VECTOR_OBJS) -o $(PATH_BINARY)$(VECTOR_NAME)
	@echo "\033[1;92m[SUCCESS] Compiled and linked $(VECTOR_NAME)\33[0m"

$(VECTOR_ITERATOR_NAME): $(VECTOR_ITERATOR_OBJS)
	@if [ ! -d $(PATH_BINARY) ]; then \
		mkdir -p $(PATH_BINARY); \
	fi
	@c++ $(CXXFLAGS) $(VECTOR_ITERATOR_OBJS) -o $(PATH_BINARY)$(VECTOR_ITERATOR_NAME)
	@echo "\033[1;92m[SUCCESS] Compiled and linked $(VECTOR_ITERATOR_NAME)\33[0m"

$(PATH_OBJS)%.o: $(PATH_VECTOR_TESTS)%.cpp
	@mkdir -p $(PATH_OBJS)
	@c++ $(CXXFLAGS) $(INCLUDE_CONTAINERS) $(INCLUDE_TESTS) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Compiled $<\33[0m"

clean:
	@rm -rf $(PATH_OBJS)
	@echo "\33[1;93m[SUCCESS] Objects removed!\33[0m"

fclean: clean
	@rm -rf $(PATH_BINARY)
	@echo "\033[1;93m[SUCCESS] Full clean done!\33[0m"

re: fclean all
	
.PHONY: all clean fclean re
