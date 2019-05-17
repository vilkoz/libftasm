#include <ctype.h>
#include <unistd.h>
#define _GNU_SOURCE			   /* See feature_test_macros(7) */
#include <fcntl.h>			   /* Obtain O_* constant definitions */
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>

static FILE		*g_file = NULL;
static int		g_save_fd = -1;

char	*read_temp_file(void)
{
		g_file = fopen("/tmp/gopa_file_temp", "rb");
		fseek(g_file, 0, SEEK_END);
		long int size = ftell(g_file);
		fseek(g_file, 0, SEEK_SET);
		char *buf = malloc(size + 1);
		fread(buf, size, 1, g_file);
		fclose(g_file);
		g_file = NULL;
		return buf;
}

void	set_stdout_to_temp_file(void)
{
		//save stdout fd
		g_save_fd = dup(STDOUT_FILENO);
		g_file = fopen("/tmp/gopa_file_temp", "w+");
		dup2(fileno(g_file), STDOUT_FILENO);
}

void	restore_stdout(void)
{
		fflush(stdout);
		fclose(g_file);
		g_file = NULL;
		dup2(g_save_fd, STDOUT_FILENO);
		close(g_save_fd);
}

#define GET_STDOUT_OUTPUT_TO(buf, expr) \
	do { \
		set_stdout_to_temp_file(); \
		expr; \
		restore_stdout(); \
		(buf) = read_temp_file(); \
	} while(0);

#define PUTS_TEST(input) \
	do { \
		char *buf_puts; \
		GET_STDOUT_OUTPUT_TO(buf_puts, puts(input)); \
		char *buf_ft; \
		GET_STDOUT_OUTPUT_TO(buf_ft, ft_puts(input)); \
		if (strcmp(buf_puts, buf_ft) != 0) \
		{ \
			printf("ERROR! input: |%s|\n", input); \
			printf("\t\t   puts: |%s|\n", buf_puts); \
			printf("\t\tft_puts: |%s|\n", buf_ft); \
		} \
		free(buf_puts); \
		free(buf_ft); \
	} while(0);

int		ft_puts(char*);

int test_puts(void)
{
	PUTS_TEST("aasdf asd fasdfqwkejrkqjefka jsdklfjakls jdklf jaslkdjfk");
	PUTS_TEST("\n\t\n   \tn \t asafsdfasdf;;df; a;sdfkj0123989837428394812");
	return (0);
}
