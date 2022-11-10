#include <stdio.h>
#include <stdlib.h>
#include "../get_next_line/get_next_line.h"

void test(size_t start, size_t len)
{
	char str[] = "0123456789abcdef";
	printf("s:%2zu l:%2zu, |%s|\n",start, len, twk_substr(str, start, len));
}

int main()
{
	test(0, 0);
	test(0, 3);
	test(0, 16);
	test(0, 17);
	test(2, 3);
	test(10, 9);
	test(16, 1);
	test(16, 3);
	test(17, 1);
	test(17, 3);
}
