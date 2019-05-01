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
}
