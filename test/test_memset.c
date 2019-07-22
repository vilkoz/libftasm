#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

void		*ft_memset(char *, char, size_t);

static int	random_test(int size)
{
	char	*s1;
	char	*s2;
	char	*res1;
	char	*res2;

	if (size == -1) {
		size = arc4random_uniform(0xfffffU);
	}
	s1 = malloc(size);
	s2 = malloc(size);
	res1 = memset(s1, 'a', size-1);
	res2 = ft_memset(s2, 'a', size-1);
	s1[size-1] = '\0';
	s2[size-1] = '\0';

	if (res2 != s2 || strncmp(s1, s2, size) != 0)
	{
		printf("ft_memset: \t|%s|\n", res1);
		printf("memset: \t|%s|\n", res2);
		return (-1);
	}
	return (0);
}

#define LINE_LEN 10

int			test_memset(void)
{
	char *s1;
	char *s2;
	char *res1;
	char *res2;

	s1 = malloc(LINE_LEN);
	s2 = malloc(LINE_LEN);
	res1 = memset(s1, 'a', LINE_LEN - 1);
	s1[LINE_LEN-1] = '\0';
	res2 = ft_memset(s2, 'a', LINE_LEN - 1);
	s2[LINE_LEN-1] = '\0';
	if (strcmp(s1, s1) != 0 || res2 != s2)
	{
		printf("ft_memset: \t|%s|\n", res1);
		printf("memset: \t|%s|\n", res2);
		return (-1);
	}
	for (int i = 0; i < 100; i++) {
		int	res;
		res = random_test(i+1);
		if (res != 0) {
			return (res);
		}
		res = random_test(-1);
		if (res != 0) {
			return (res);
		}
	}
	return (0);
}
