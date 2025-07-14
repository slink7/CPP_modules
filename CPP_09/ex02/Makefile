#=== Project Config ===

NAME = FJ

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

shuf:
	shuf -e $({1..32})

test: all
	./$(NAME) 9 8 7 6 5 4 3 2 1 0
	./$(NAME) 9 8 7 6 0 5 4 3 2 1
	./$(NAME) 0 458 6 2 16
	./$(NAME) 1 0
	./$(NAME) 0 1
	./$(NAME) 8 7 2 0 4
	./$(NAME) 1 5 7 8 3 4 8	
	./$(NAME) 22 13 20 1 7 4 27 30 3 11 26 24 23 17 5 29 8 28 15 12 21 2 9 32 14 16 10 18 31 19 25 6
	echo =======================
	./$(NAME) 0
	./$(NAME) 1 0
	./$(NAME) 2 1 0
	./$(NAME) 3 2 1 0
	./$(NAME) 4 3 2 1 0
	./$(NAME) 5 4 3 2 1 0
	./$(NAME) 6 5 4 3 2 1 0


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