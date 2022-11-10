# include <fcntl.h>
# include <stdio.h>
# include "../get_next_line/get_next_line.h"

# define TWK_SIZE 50
void print_buff(char *buffer)
{
	printf("<<<");
	for (int i = 0; i < TWK_SIZE; i++)
		printf("%c", buffer[i]);
	printf(">>>\n");
}
int main(void)
{
	int		fd;
	char	*buff;
	
	buff = malloc(sizeof(char) * (TWK_SIZE));
	for (int i = 0; i < TWK_SIZE; i++)
	{
		buff[i] = 'O';
	}
	buff[0] = '\0';
	print_buff(buff);
	
	fd = open("inp_file.txt", O_RDONLY);
	//while(read(fd, str, 2) > 0 && write(1, str, 2) > 0);
	printf("Readed: %zu", fill_buffer(&buff, fd));
	printf("\nbuff: <<%s>>\n", buff);
	close(fd);
}
	
