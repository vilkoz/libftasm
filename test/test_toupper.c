#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int		ft_toupper(int);

int test_toupper(void)
{
	for (char test_case = -127; test_case < 127; test_case++) {
		if (ft_toupper(test_case) != toupper(test_case)) {
			printf("ft_toupper, should return %d for %d\n",
					toupper(test_case), test_case);
			return (-1);
		}
	}
	return (0);
}
