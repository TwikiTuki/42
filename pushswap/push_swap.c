# include <stdlib.h>
# include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 1)
	{
		ft_printf("Error\n");
		return (0);
	}

	if (!psw_check(argv))
	{
		ft_printf("Error\n");
		return (0);
	}
}
