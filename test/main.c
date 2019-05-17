#include "test_list.h"
#include <stdio.h>

#define RUN_TEST(test)					\
{										\
	if ((test)()) {						\
		printf(#test": error\n");		\
	} else {							\
		printf(#test": OK\n");			\
	}									\
}

int main(void)
{
	RUN_TEST(test_bzero);
	RUN_TEST(test_strcat);
	RUN_TEST(test_isalpha);
	RUN_TEST(test_isascii);
	RUN_TEST(test_isdigit);
	RUN_TEST(test_isalnum);
	RUN_TEST(test_isprint);
	RUN_TEST(test_toupper);
	RUN_TEST(test_tolower);
	RUN_TEST(test_puts);
}
