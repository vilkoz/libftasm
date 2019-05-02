#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int		ft_isalpha(char);

#define ISALPHA_TESTCASE(test_case) { 						\
	if (ft_isalpha(test_case) != isalpha(test_case)) { 		\
		printf("ft_isalpha, should return %d for %s\n", 	\
				isalpha(test_case), "#test_case"); 			\
		return (-1); 										\
	} 														\
}

int test_isalpha(void)
{
	ISALPHA_TESTCASE('A' - 1);
	ISALPHA_TESTCASE('A' + 1);
	ISALPHA_TESTCASE('Z' - 1);
	ISALPHA_TESTCASE('Z' + 1);
	ISALPHA_TESTCASE('a' - 1);
	ISALPHA_TESTCASE('a' + 1);
	ISALPHA_TESTCASE('z' - 1);
	ISALPHA_TESTCASE('z' + 1);
	return (0);
}
