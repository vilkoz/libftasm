#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

void		*ft_memcpy(char *, char*, size_t);

static int	random_test(int size)
{
	char *s1;
	char *s2;
	char *d1;
	char *d2;
	char *res1;
	char *res2;

	if (size == -1) {
		size = arc4random_uniform(0xfffffU);
	}

	s1 = malloc(size);
	s2 = malloc(size);
	s1[size-1] = '\0';
	s2[size-1] = '\0';
	d1 = malloc(size);
	d2 = malloc(size);
	s1 = memset(s1, 'a', size-1);
	s2 = memset(s2, 'a', size-1);
	res1 = memcpy(d1, s1, size);
	res2 = ft_memcpy(d2, s2, size);
	if (memcmp(d1, d2, size) != 0 || res2 != d2)
	{
		printf("ft_memcpy: \t|%s|\n", res1);
		printf("memcpy: \t|%s|\n", res2);
		return (-1);
	}
	return (0);
}

static int	test_error_input(void)
{
	char *res = NULL;
	char *s = malloc(10);
	char *d = malloc(10);

	memset(s, 's', 10);
	memset(d, 'd', 10);
	res = ft_memcpy(NULL, d, 10);
	if (res != NULL) {
		printf("ft_memcpy: wrong return value: %p\n", res);
		return (1);
	}
	res = ft_memcpy(s, NULL, 10);
	if (res != NULL) {
		printf("ft_memcpy: wrong return value: %p\n", res);
		return (1);
	}
	res = ft_memcpy(s, d, 0);
	if (res != NULL) {
		printf("ft_memcpy: wrong return value: %p\n", res);
		return (1);
	}
	res = ft_memcpy(s, d, -1);
	if (res != NULL) {
		printf("ft_memcpy: wrong return value: %p\n", res);
		return (1);
	}
	return (0);
}

#define LINE_LEN 10

int			test_memcpy(void)
{
	char *s1;
	char *s2;
	char *d1;
	char *d2;
	char *res1;
	char *res2;

	s1 = malloc(LINE_LEN);
	s2 = malloc(LINE_LEN);
	s1[LINE_LEN-1] = '\0';
	s2[LINE_LEN-1] = '\0';
	d1 = malloc(LINE_LEN);
	d2 = malloc(LINE_LEN);
	s1 = memset(s1, 'a', LINE_LEN-1);
	s2 = memset(s2, 'a', LINE_LEN-1);
	res1 = memcpy(d1, s1, LINE_LEN);
	res2 = ft_memcpy(d2, s2, LINE_LEN);
	if (memcmp(d1, d2, LINE_LEN) != 0 || res2 != d2)
	{
		printf("ft_memcpy: \t|%s|, |%s|\n", res2, d2);
		printf("memcpy: \t|%s|, |%s|\n", res1, d1);
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
	if (test_error_input()) {
		return (1);
	}
	return (0);
}
