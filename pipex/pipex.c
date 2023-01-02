#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "libft/get_next_line/get_next_line_bonus.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/libft/libft.h"

char    *ft_strjoin(char const *s1, char const *s2);

char *get_path(char *program)
{	
	return (ft_strjoin("/bin/", program));
}

int call(char *argv[], char *envp[], int inp, int out)
{
	char	*path;
	int		err;
	pid_t pid;

	pid = fork();
	if (!pid)
	{
		dup2(0, inp);
		dup2(1, out);
		path = get_path(argv[0]);
		execve(path, argv + 1, envp);
		free(path);
		exit(0);
	}
	else
		wait(&err);
	return (err);
}

int main(void)
{
	char *args[3];
	char str0[] = "grep";
	char str1[] = "a";
	int inp;
	int	out;

	args[0] = str0;
	args[1] = str1;
	args[2] = NULL;
	
	inp = open("./inp_file", O_WRONLY);
	out = open("./out_file", O_RDONLY);
	if (call(args, NULL, inp, out))
		ft_printf("\nSome error ocurred when on call()\n");
	else
		ft_printf("\nNo error courred on call()\n");
}
