NAME=libftasm

TEST=run_test

SRC_NAMES= bzero.S				\
		   strcat.S				\
		   isalpha.S			\
		   isascii.S			\
		   isdigit.S			\
		   isalnum.S			\

SRC=$(addprefix src/, $(SRC_NAMES))

BINS=$(addprefix bin/, $(SRC_NAMES:.S=.o))

all: $(NAME)

bin/%.o: src/%.S
	@mkdir -p $(shell dirname $@)
	nasm -f macho64 $< -o $@

$(NAME): $(BINS)
	ar rcu $(NAME) $(BINS)

TEST_SRC_NAMES = test_bzero.c					\
				 test_strcat.c					\
				 test_isalpha.c					\
				 test_isascii.c					\
				 test_isdigit.c					\
				 test_isalnum.c					\
				 main.c

TEST_SRC=$(addprefix test/, $(TEST_SRC_NAMES))

TEST_BINS=$(addprefix bin/test/, $(TEST_SRC_NAMES:.c=.o))

bin/test/%.o: test/%.c
	@mkdir -p $(shell dirname $@)
	gcc -g -c $< -o $@

$(TEST): $(NAME) $(TEST_BINS)
	gcc -g -Wall -Wextra -Werror -o $(TEST) $(TEST_BINS) $(NAME)

test: $(TEST)
	./$(TEST)

clean:
	rm -rf $(BINS) $(TEST_BINS)

fclean: clean
	rm -rf $(NAME) $(TEST)

re: clean all

.PHONY: re fclean clean all test