#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int		ft_isdigit(int);

#define ISDIGIT_TESTCASE(test_case) { 						\
	if (ft_isdigit(test_case) != isdigit(test_case)) { 		\
		printf("ft_isdigit, should return %d for %d\n", 	\
				isdigit(test_case), test_case); 			\
		return (-1); 										\
	} 														\
}

int test_isdigit(void)
{
	for (char i = -127; i < 127; i++) {
		ISDIGIT_TESTCASE(i);
	}
	return (0);
}
