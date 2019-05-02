#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int		ft_isalnum(int);

#define ISALNUM_TESTCASE(test_case) { 						\
	if (ft_isalnum(test_case) != isalnum(test_case)) { 		\
		printf("ft_isalnum, should return %d for %d\n", 	\
				isalnum(test_case), test_case); 			\
		return (-1); 										\
	} 														\
}

int test_isalnum(void)
{
	for (char i = 0; i < 127; i++) {
		if (ft_isalnum(i) != isalnum(i)) {
			printf("ft_isalnum, should return %d for %d\n",
					isalnum(i), i);
			return (-1);
		}
	}
	return (0);
}
