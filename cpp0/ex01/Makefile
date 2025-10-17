CC = c++

INCLUDE_DIR = include

INCLUDE = $(INCLUDE_DIR)/PhoneBook.h $(INCLUDE_DIR)/Contact.h

IFLAGS = -I $(INCLUDE_DIR)

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = srcs/

SRC = main.cpp Contact.cpp PhoneBook.cpp

BUILD_DIR = .build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

DEP = $(OBJ:.o=.d)

NAME = phonebook

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