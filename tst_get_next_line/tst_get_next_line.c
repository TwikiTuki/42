# include <stdio.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"

int	main(void)
{
	int	fd;
	char *line;
	
	fd = open("inp_file.txt", O_RDONLY);
	fd = 60;
	for (int i = 0; i < 8; i++)
	{
		line = NULL;
		line = get_next_line(fd);
		printf("<<%s>>\n", line);
		free(line);
	}

}
