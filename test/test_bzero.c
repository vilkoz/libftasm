#include <stdlib.h>
#include <string.h>

void		ft_bzero(void *, size_t);

static int	test_null_arg(void)
{
	char	*s;

	s = malloc(10);
	ft_bzero(s, 10);
	s[0] = 'a';
	ft_bzero(s, 0);
	if (s[0] != 'a')
		return (-1);
	return (0);
}

int			test_bzero(void)
{
	char	*s1 = malloc(10);
	char	*s2 = malloc(10);
	int		ret = 0;

	memset(s1, 'a', 10);
	memset(s2, 'a', 10);
	ft_bzero(s1, 5);
	bzero(s2, 5);
	if (memcmp(s1, s2, 10) != 0)
		return (-1);
	ret = test_null_arg();
	if (ret != 0)
		return (ret);
	return (0);
}
