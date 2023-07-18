VECTOR_NAME = vectors
ITERATOR_NAME = iterator

PATH_VECTOR = ./sources/vector/
PATH_ITERATOR = ./tests/iterator/
PATH_CONTAINERS = ./includes/
PATH_TESTS = ./tests/
PATH_OBJS = ./objects/

VECTOR_TESTS =	main_vectors.cpp
VECTOR_OBJS = $(patsubst %.cpp,$(PATH_OBJS)%.o,$(VECTOR_TESTS))

ITERATOR_TESTS =	iteratorTests.cpp
ITERATOR_OBJS = $(patsubst %.cpp,$(PATH_OBJS)%.o,$(ITERATOR_TESTS))

INCLUDE_CONTAINERS = -I $(PATH_CONTAINERS)
INCLUDE_TESTS = -I $(PATH_TESTS)
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

tests: $(VECTOR_NAME) $(ITERATOR_NAME)

vector-run: $(VECTOR_NAME)
	@./$(VECTOR_NAME)

iterator-run: $(ITERATOR_NAME)
	@./$(ITERATOR_NAME)

$(VECTOR_NAME): $(VECTOR_OBJS)
	@c++ $(FLAGS) $(VECTOR_OBJS) -o $(VECTOR_NAME)

$(PATH_OBJS)%.o: $(PATH_VECTOR)%.cpp
	@mkdir -p $(PATH_OBJS)
	@c++ $(FLAGS) $(INCLUDE_CONTAINERS) $(INCLUDE_TESTS) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Vector object creation done!\033[0m"

$(ITERATOR_NAME): $(ITERATOR_OBJS)
	@c++ $(FLAGS) $(ITERATOR_OBJS) -o $(ITERATOR_NAME)

$(PATH_OBJS)%.o: $(PATH_ITERATOR)%.cpp
	@mkdir -p $(PATH_OBJS)
	@c++ $(FLAGS) $(INCLUDE_CONTAINERS) $(INCLUDE_TESTS) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Vector object creation done!\033[0m"

clean:
	@rm -rf $(PATH_OBJS)
	@echo "\33[1;93m[SUCCESS] Objects removed!\33[0m"

fclean: clean
	@rm -f $(VECTOR_NAME)
	@echo "\033[1;93m[SUCCESS] Full clean done!\33[0m"

re: fclean tests
	
.PHONY: tests clean fclean re
