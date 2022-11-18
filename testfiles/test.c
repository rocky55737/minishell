#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#include <readline/readline.h>

void	sigint_handler(int	sig);

int main(void)
{
	//readline stat test
	char	*buff;
	struct stat struct_stat;
	do
	{
		buff = readline("minishell $");
		if (stat(buff, &struct_stat) == -1)
			strerror(errno);
		printf("%d\n", (int)struct_stat.st_mode);
		if ((struct_stat.st_mode & 0170000) == 0040000)
			printf("isdir\n");
	} while (buff);

	//isatty test
	// char	*buff;
	// int		fd;
	// buff = readline("");
	// fd = open(buff, O_RDONLY);
	// printf("%d", isatty(fd));
	// close(fd);

	//chdir test
	// char	*buff;
	// char	pwd[100];
	// memset(pwd, 0, 100);
	// getcwd(pwd, 100);
	// printf("%s\n", pwd);
	// buff = readline("");
	// printf("%d\n", chdir(buff));
	// memset(pwd, 0, 100);
	// getcwd(pwd, 100);
	// printf("%s\n", pwd);
	// while (1)
	// {}

	// pid_t	pid;
	// int		status;
	// struct rusage s_rusage;

	// pid = fork();
	// signal(2, sigint_handler);
	// if (pid == 0)
	// {
	// 	while (1)
	// 	{
	// 	}
	// }
	// else
	// {
	// 	system("sleep 5\n");
	// 	kill(pid, 3);
	// 	wait4(pid, &status, 0, &s_rusage);
	// 	printf("usag: %d\n", getrusage());
	// }
	return (0);
}

//signal function
// void	sigint_handler(int	sig)
// {
// 	write(2, "the sigint called!\n", strlen("the sigint called!\n"));
// 	exit(1);
// }