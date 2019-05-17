#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int		ft_tolower(int);

int test_tolower(void)
{
	for (char test_case = -127; test_case < 127; test_case++) {
		if (ft_tolower(test_case) != tolower(test_case)) {
			printf("ft_tolower, should return %d for %d\n",
					tolower(test_case), test_case);
			return (-1);
		}
	}
	return (0);
}
