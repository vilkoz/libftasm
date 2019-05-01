#include <stdlib.h>
#include <string.h>

void		ft_bzero(void *, size_t);

int			test_bzero(void)
{
	char  *s1 = malloc(10);
	char  *s2 = malloc(10);

	memset(s1, 'a', 10);
	memset(s2, 'a', 10);
	ft_bzero(s1, 5);
	bzero(s2, 5);
	if (memcmp(s1, s2, 10) != 0)
		return (-1);
	return (0);
}
