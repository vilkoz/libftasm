#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

size_t		ft_strlen(char *);

static int	random_test(void)
{
	char	*s;
	int		size;
	size_t	res1;
	size_t	res2;

	size = arc4random_uniform(0xfffffU);
	s = malloc(size);
	memset(s, 'a', size-1);
	s[size-1] = '\0';

	res1 = ft_strlen(s);
	res2 = strlen(s);
	if (res1 != res2)
	{
		printf("ft_strlen: \t|%zu|\n", res1);
		printf("strlen: \t|%zu|\n", res2);
		return (-1);
	}
	return (0);
}

int			test_strlen(void)
{
	char *s1;
	size_t res1;
	size_t res2;

	s1 = malloc(0xbeef);
	memset(s1, 'a', 0xbeef - 1);
	s1[0xbeef-1] = '\0';
	res1 = ft_strlen(s1);
	res2 = strlen(s1);
	if (res1 != res2)
	{
		printf("ft_strlen: \t|%zu|\n", res1);
		printf("strlen: \t|%zu|\n", res2);
		return (-1);
	}
	for (int i = 0; i < 100; i++) {
		int	res;
		res = random_test();
		if (res != 0) {
			return (res);
		}
	}
	return (0);
}
