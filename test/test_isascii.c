#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int		ft_isascii(int);

#define ISASCII_TESTCASE(test_case) { 						\
	if (ft_isascii(test_case) != isascii(test_case)) { 		\
		printf("ft_isascii, should return %d for %d\n", 	\
				isascii(test_case), test_case); 			\
		return (-1); 										\
	} 														\
}

int test_isascii(void)
{
	for (int i = -256; i < 256; i++) {
		ISASCII_TESTCASE(i);
	}
	return (0);
}
