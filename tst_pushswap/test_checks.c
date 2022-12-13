# include <stdlib.h>
# include "../pushswap/push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 0)
		return (0);
	if (!psw_check(argv + 1))
	{
		ft_printf("Error\n");
		return (0);
	}
	else
		ft_printf("OK\n");
}
