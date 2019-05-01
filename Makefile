NAME=libftasm

TEST=run_test

SRC_NAMES= bzero.S				\
		   strcat.S

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
				 main.c

TEST_SRC=$(addprefix test/, $(TEST_SRC_NAMES))

TEST_BINS=$(addprefix bin/test/, $(TEST_SRC_NAMES:.c=.o))

bin/test/%.o: test/%.c
	@mkdir -p $(shell dirname $@)
	gcc -c $< -o $@

$(TEST): $(NAME) $(TEST_BINS)
	gcc -Wall -Wextra -Werror -o $(TEST) $(TEST_BINS) $(NAME)

test: $(TEST)
	./$(TEST)

clean:
	rm -rf $(BINS)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: re fclean clean all test
