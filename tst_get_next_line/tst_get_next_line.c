# include <stdio.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../get_next_line/get_next_line_bonus.h"

int	main(void)
{
	int	fd;
	char *line;

	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	
	fd = open("inp_file.txt", O_RDONLY);
	for (int i = 0; i < 8; i++)
	{
		line = NULL;
		line = get_next_line(fd);
		printf("<<%s>>\n", line);
		free(line);
	}

}
