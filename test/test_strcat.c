#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void		ft_strcat(char *, char *);

int			test_strcat(void)
{
	char  *s1 = malloc(20);
	char  *s2 = malloc(10);
	char  *s11 = malloc(20);
	char  *s21 = malloc(10);
	char  *s1_save = s1;

	bzero(s1, 10);
	bzero(s2, 10);
	bzero(s11, 10);
	bzero(s21, 10);
	memset(s1, 'a', 9);
	memset(s2, 'b', 9);
	memset(s11, 'a', 9);
	memset(s21, 'b', 9);
	ft_strcat(s1, s2);
	strcat(s11, s21);
	if (memcmp(s1, s11, 18) != 0)
	{
		printf("ft_strcat: \t|%s|\n", s1);
		printf("strcat: \t|%s|\n", s11);
		return (-1);
	}
	if (s1 != s1_save)
	{
		puts("ft_strcat returned not s1!\n");
		return (-1);
	}
	return (0);
}
