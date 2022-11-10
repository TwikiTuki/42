#include "../get_next_line/get_next_line.h"
#include <stdio.h>

int	main()
{
	//hello you
	//0123456789
	printf("%d\n", twk_strchr("hello you", 'h'));
	printf("%d\n", twk_strchr("hello you", 'u'));
	printf("%d\n", twk_strchr("hello you", ' '));
	printf("%d\n", twk_strchr("hello you", '\0'));
	printf("%d\n", twk_strchr("hello you", 'z'));
}
