STL_VECTOR_NAME = stl_vector

PATH_VECTOR = ./sources/vector/
PATH_CONTAINERS = ./includes/
PATH_OBJS = ./objects/

VECTOR_TESTS =	main_stl.cpp

VECTOR_OBJS = $(patsubst %.cpp,$(PATH_OBJS)%.o,$(VECTOR_TESTS))

INCLUDE = -I $(PATH_CONTAINERS)
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

tests: $(STL_VECTOR_NAME)

$(STL_VECTOR_NAME): $(VECTOR_OBJS)
	@c++ $(FLAGS) $(VECTOR_OBJS) -o $(STL_VECTOR_NAME)

$(PATH_OBJS)%.o: $(PATH_VECTOR)%.cpp
	@mkdir -p $(PATH_OBJS)
	@c++ $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Vector object creation done!\033[0m"

clean:
	@rm -rf $(PATH_OBJS)
	@echo "\33[1;93m[SUCCESS] Objects removed!\33[0m"

fclean: clean
	@rm -f $(STL_VECTOR_NAME)
	@echo "\033[1;93m[SUCCESS] Full clean done!\33[0m"

re: fclean tests
	
.PHONY: tests clean fclean re
