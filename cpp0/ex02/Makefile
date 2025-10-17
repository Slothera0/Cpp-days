CC = c++

CFLAGS = -std=c++98

SRC_DIR = .

SRC = tests.cpp Account.cpp

BUILD_DIR = .build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

DEP = $(OBJ:.o=.d)

NAME = bank

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

-include $(DEP)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp Account.hpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

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