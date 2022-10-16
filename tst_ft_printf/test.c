#include "../ft_printf/ft_printf.h"
//#include "../ft_printf/ft_printf.k"
//#include "ft_printf.h"

void tst_str(char *str)
{
	int ftrs;
	int	lbrs;

	printf("****************\n");
	ft_printf("----------------\n");
	ftrs = ft_printf("%s", str);
	ft_printf("\n");
	lbrs = printf("%s", str);
	printf("\n");

	if (ftrs != lbrs)
		printf("ERROR: ");
	printf("ftrs: %d, lbrs %d", ftrs, lbrs);
	printf("\n");
	
	printf("----------------\n");
	ft_printf("****************\n");
}

void tst_char(char c)
{
	int ftrs;
	int	lbrs;

	printf("****************\n");
	ft_printf("----------------\n");
	ft_printf("|");
	ftrs = ft_printf("%c", c);
	ft_printf("|");
	ft_printf("\n");
	printf("|");
	lbrs = printf("%c", c);
	printf("|");
	printf("\n");

	if (ftrs != lbrs)
		ft_printf("ERROR: ");
	ft_printf("ftrs: %d, lbrs %d", ftrs, lbrs);
	ft_printf("\n");
	ft_printf("----------------\n");
	printf("****************\n");
}

void test_strings(void)
{
	printf("\nTEST_CHARS\n");
	tst_char('c');
	tst_char(0);
	tst_char('0');

	printf("\nTEST_STRINGS\n");
	tst_str("sdaf");
	tst_str("s");
	tst_str("");
	tst_str(NULL);
	printf("\nTEST_UNSIGNED_INTS\n");
}

void test_uint(size_t n, char type)
{
	int ftrs;
	int	lbrs;
	char format[] = "%a";

	format[1] = type;
	
	printf("****************\n");
	ft_printf("----------------\n");
	ft_printf("|");
	ftrs = ft_printf(format, n);
	ft_printf("|");
	ft_printf("\n");
	printf("|");
	lbrs = printf(format, n);
	printf("|");
	printf("\n");

	if (ftrs != lbrs)
		ft_printf("ERROR: ");
	ft_printf("ftrs: %d, lbrs %d", ftrs, lbrs);
	ft_printf("\n");
	ft_printf("----------------\n");
	printf("****************\n");
	// not testing for negative inputs
}

void test_ints(int n, char type)
{
	int ftrs;
	int	lbrs;
	char format[] = "%a";

	format[1] = type;
	
	printf("****************\n");
	ft_printf("----------------\n");
	ft_printf("|");
	ftrs = ft_printf(format, n);
	ft_printf("|");
	ft_printf("\n");
	printf("|");
	lbrs = printf(format, n);
	printf("|");
	printf("\n");

	if (ftrs != lbrs)
		ft_printf("ERROR: ");
	ft_printf("ftrs: %d, lbrs %d", ftrs, lbrs);
	ft_printf("\n");
	ft_printf("----------------\n");
	printf("****************\n");
}

void test_numbers(void)
{
	int			i;

	printf("TESTING u\n");
	test_uint(5, 'u');
	test_uint(58, 'u');
	test_uint(0, 'u');

	printf("TESTING xXp\n");
	test_uint((unsigned int)&i, 'x');
	test_uint((unsigned int)&i, 'X');
	test_uint((unsigned int)&i, 'p');
	test_uint((unsigned int)NULL, 'p');
	test_uint(0, 'x');
	test_uint(0, 'X');
	test_uint(255, 'x');
	test_uint(255, 'X');

	printf("TESTING d i\n");
	test_ints(0, 'd');
	test_ints(0, 'i');
	test_ints(255, 'd');
	test_ints(255, 'i');
	test_ints(-255, 'd');
	test_ints(-255, 'i');
	test_ints((int) -2147483648, 'd');
	test_ints((int) -2147483648, 'i');
	test_ints((int) 2147483648, 'd');
	test_ints((int) 2147483648, 'i');
	test_ints((int) 2147483647, 'd');
	test_ints((int) 2147483647, 'i');
}

void others(void)
{
	int ftrs;

	ftrs = ft_printf("|%c|", 'x');
	printf("\n");
	printf("ftrs: %d\n", ftrs);
	ftrs = ft_printf("|%c |", 'x');
	printf("\n");
	printf("ftrs: %d\n", ftrs);
	
	printf("\n");
	ft_printf("|");
	ftrs = ft_printf("%s", "sdaf");
	ft_printf("|");
	printf("\n");
	printf("ftrs: %d\n", ftrs);
	ft_printf("|");
	ftrs = ft_printf("%s ", "fdsdsasd");
	ft_printf("|");
	printf("\n");
	printf("ftrs: %d\n", ftrs);

}

int main(void)
{
	others();
	return  (0);
	test_strings();
	test_numbers();
}
