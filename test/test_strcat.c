#include <stdlib.h>
#include <string.h>

void		ft_strcat(char *, char *);

int			test_strcat(void)
{
	char  *s1 = malloc(20);
	char  *s2 = malloc(10);
	char  *s11 = malloc(20);
	char  *s21 = malloc(10);

	bzero(s1, 10);
	bzero(s2, 10);
	bzero(s11, 10);
	bzero(s21, 10);
	memset(s1, 'a', 10);
	memset(s2, 'a', 10);
	memset(s11, 'a', 10);
	memset(s21, 'a', 10);
	ft_strcat(s1, s2);
	strcat(s11, s21);
	if (memcmp(s1, s11, 20) != 0)
		return (-1);
	return (0);
}
