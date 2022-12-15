#include "../pushswap/push_swap.h"

void test_boundaries_usless(size_t len)
{
	size_t	start;
	size_t	boundaries[4];
	int		chuncks;
	int		chunck;

	chuncks = 1;
	while (chuncks <= 4)
	{
		chunck = 0;
		start = 0;
		printf("len: %zu, chuncks: %d\n", len, chuncks);
		while (chunck++ < chuncks)
		{
			psw_boundaries(boundaries, chunck, start, len);
			start = boundaries[0] + 1;
			for (int i = 0; i < 4; i++)
				ft_printf("%d ", boundaries[i]);
			ft_printf("\n");
		}
		chuncks++;
	}
}


void test_boundaries(size_t len)
{
	size_t	start;
	size_t	boundaries[4];
	int		chunck;

	ft_printf("len %d\n", len);
	chunck = 0;
	start = 0;
	while (chunck++ < CHUNCKS)
	{
		psw_boundaries(boundaries, chunck, start, len);
		start = boundaries[3] + 1;
		for (int i = 0; i < 4; i++)
			ft_printf("%d ", boundaries[i]);
		ft_printf("\n");
	}
	ft_printf("\n");
}


int	main(void)
{
	test_boundaries(10);
	test_boundaries(25);
	test_boundaries(34);
	test_boundaries(50);
	test_boundaries(100);
	test_boundaries(200);
	test_boundaries(500);
	test_boundaries(1000);
	test_boundaries(2000);
	test_boundaries(5000);
}
