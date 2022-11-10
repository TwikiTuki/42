#include "../get_next_line/get_next_line.c"
#include <stdio.h>

// This tests needs to change the twk_lazzy_calloc functino
// It expects the function to initialize all the memory to 1 beffore nullending.
void	test(size_t ammount, size_t size)
{
	char	*mem;
	int		sum;

	printf("testing: ");
	mem = twk_lazzy_calloc(ammount, size);
	sum = 0;
	for (size_t i = 0; i <  ammount * size; i++)
	{
		printf("%d, ", mem[i]);
		sum += mem[i];
	}
	printf("\n");
	printf("sum: %d\n", sum);
}

int main(void)
{
	test(0, 0);
	test(0, 5);
	test(10, 0);
	test(10, 4);
	test(10, 3);
	test(10, 1);
}
