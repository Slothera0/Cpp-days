CC = c++

INCLUDE_DIR = include

INCLUDE = $(INCLUDE_DIR)/Zombie.h

IFLAGS = -I $(INCLUDE_DIR)

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = srcs/

SRC = main.cpp zombieHorde.cpp Zombie.cpp

BUILD_DIR = .build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

DEP = $(OBJ:.o=.d)

NAME = ex01

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

-include $(DEP)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: FORCE
FORCE:

.PHONY: re
re: fclean
	$(MAKE) all