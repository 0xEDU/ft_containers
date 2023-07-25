VECTOR_NAME = vectors
VECTOR_ITERATOR_NAME = vector_iterator

PATH_VECTOR = ./sources/vector/
PATH_VECTOR_ITERATOR = ./tests/vector_iterator/
PATH_CONTAINERS = ./includes/
PATH_TESTS = ./tests/
PATH_OBJS = ./objects/

VECTOR_TESTS =	main_vectors.cpp
VECTOR_OBJS = $(patsubst %.cpp,$(PATH_OBJS)%.o,$(VECTOR_TESTS))

VECTOR_ITERATOR_TESTS =	vector_iterator_tests.cpp
VECTOR_ITERATOR_OBJS = $(patsubst %.cpp,$(PATH_OBJS)%.o,$(VECTOR_ITERATOR_TESTS))

INCLUDE_CONTAINERS = -I $(PATH_CONTAINERS)
INCLUDE_TESTS = -I $(PATH_TESTS)
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

all: $(VECTOR_NAME) $(VECTOR_ITERATOR_NAME)

vector-run: $(VECTOR_NAME)
	@./$(VECTOR_NAME)
	@rm -rf $(VECTOR_NAME)

vector-iterator-run: $(VECTOR_ITERATOR_NAME)
	@./$(VECTOR_ITERATOR_NAME)

$(VECTOR_NAME): $(VECTOR_OBJS)
	@c++ $(FLAGS) $(VECTOR_OBJS) -o $(VECTOR_NAME)

$(PATH_OBJS)%.o: $(PATH_VECTOR)%.cpp
	@mkdir -p $(PATH_OBJS)
	@c++ $(FLAGS) $(INCLUDE_CONTAINERS) $(INCLUDE_TESTS) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Vector test objects creation done!\033[0m"

$(VECTOR_ITERATOR_NAME): $(VECTOR_ITERATOR_OBJS)
	@c++ $(FLAGS) $(VECTOR_ITERATOR_OBJS) -o $(VECTOR_ITERATOR_NAME)

$(PATH_OBJS)%.o: $(PATH_VECTOR_ITERATOR)%.cpp
	@mkdir -p $(PATH_OBJS)
	@c++ $(FLAGS) $(INCLUDE_CONTAINERS) $(INCLUDE_TESTS) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Vector iterator test objects creation done!\033[0m"

clean:
	@rm -rf $(PATH_OBJS)
	@echo "\33[1;93m[SUCCESS] Objects removed!\33[0m"

fclean: clean
	@rm -f $(VECTOR_NAME) $(VECTOR_ITERATOR_NAME)
	@echo "\033[1;93m[SUCCESS] Full clean done!\33[0m"

re: fclean all
	
.PHONY: all clean fclean re
