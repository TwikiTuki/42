# include <stdio.h>
# include "../get_next_line/get_next_line.h"

void test(char *s1, char *s2)
{
	printf("|%s|, |%s|\n", s1, s2);
	printf("|%s|\n", twk_strjoin(s1, s2));
	printf("\n");
}

int main(void)
{
	test(NULL, NULL);
	test(NULL, "sdaf");
	test("fasd", NULL);
	test("Kolo", "Sule");
	test("", "Sule");
	test("Kolo", "");
	test("", "");
}

