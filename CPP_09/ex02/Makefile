#=== Project Config ===

NAME = RPN

COMPILER = c++

SRC = \
	main.cpp

CFLAGS = -Wall -Werror -Wextra -g3 -std=c++98
LFLAGS =

INCLUDES =\
	-I./\

OBJ_DIR = obj

#=== Automatic Vars ===

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRC))))

#=== Targets ===

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp
	$(COMPILER) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(NAME) : $(OBJ_DIR) $(LIBS) $(OBJ)
	$(COMPILER) -o $(NAME) $(OBJ) $(LFLAGS)

clean :
	rm -rf $(OBJ_DIR) || true

fclean : clean
	rm -f $(NAME) $(NAME_BONUS) || true

re : fclean all

.PHONY : re fclean clean all