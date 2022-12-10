# include "../pushswap/push_swap.h"

void	test(char *str)
{
	ft_printf(">>%s<< -->", str);
	psw_clean(str);
	ft_printf(" >>%s<<\n", str);
}
int main(void)
{
	test("+12345");
	test("-12345");
	test("012345");
	test("000012345");
	test("-000012345");
	test("+000012345");
}
