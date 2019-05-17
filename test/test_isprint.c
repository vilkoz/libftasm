#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int		ft_isprint(int);

int test_isprint(void)
{
	for (char test_case = -127; test_case < 127; test_case++) {
		if (ft_isprint(test_case) != isprint(test_case)) {
			printf("ft_isprint, should return %d for %d\n",
					isprint(test_case), test_case);
			return (-1);
		}
	}
	return (0);
}
