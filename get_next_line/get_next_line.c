# include "get_next_line.h"

# define BUFFER_SIZE 4

void *abort_buffer(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

ssize_t	fill_buffer(char **buffer, int fd)
{
	char		*nw_buffer;
	char		nw_str[BUFFER_SIZE + 1]; 
	ssize_t		readed;

	readed = read(fd, nw_str, BUFFER_SIZE);
	if (readed <= 0)
		return (readed);
	nw_str[readed] = '\0';
	nw_buffer = twk_strjoin(*buffer, nw_str);
	if (*buffer)
		free(*buffer);
	*buffer = nw_buffer;
	if (!*buffer)
		return (-1);
	return (readed);
}

char *get_line(char **buffer)
{
	int		end;
	char	*result;
	char	*nw_buffer;

	end = twk_strchr(*buffer, '\n') + 1;
	result = twk_substr(*buffer, 0, end);
	if (!result)
		return(abort_buffer(buffer));
	nw_buffer = twk_substr(*buffer, end, twk_strlen(*buffer) - end);
	free(*buffer);
	*buffer = nw_buffer;
	if(!buffer)
		return (abort_buffer(&result));
	return (result);
}
	
char *get_next_line(int fd)
{
	static char	*buffer;
	char		*buffer2;
	ssize_t		readed;

	if(!buffer)
		buffer = twk_lazzy_calloc(1, sizeof(char)); 
	if(!buffer)
		return (NULL);
	readed = 1;
	while(buffer && twk_strchr(buffer, '\n') == -1 && readed > 0)
		readed = fill_buffer(&buffer, fd);
	if (readed == -1)
		return (abort_buffer(&buffer));
	if(readed == 0)
	{
		buffer2 = twk_substr(buffer, 0, twk_strlen(buffer));
		abort_buffer(&buffer);
		return(buffer2); 
	}
	return (get_line(&buffer));
}
