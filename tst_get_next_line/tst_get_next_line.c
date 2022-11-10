# include <stdio.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"

int	main(void)
{
	int	fd;
	
	fd = open("inp_file.txt", O_RDONLY);
	for (int i = 0; i < 6; i++)
	{
		printf("<<%s>>\n", get_next_line(fd));
	}

}
