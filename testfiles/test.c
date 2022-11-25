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
	//char	*buff;
	//struct stat struct_stat;
	//do
	//{
	//	buff = readline("minishell $");
	//	if (stat(buff, &struct_stat) == -1)
	//		strerror(errno);
	//	printf("%d\n", (int)struct_stat.st_mode);
	//	if ((struct_stat.st_mode & 0170000) == 0040000)
	//		printf("isdir\n");
	//} while (buff);

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

	// signal test
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		signal(2, multi_sig_handler_child);
		signal(3, multi_sig_handler_child);
		signal(15, multi_sig_handler_child);
		while (1)
		{
		}
	}
	else
	{
		signal(2, parent);
		waitpid(pid, &status, 0);
		exit(status >> 8);
	}
	return (0);
}

//signal function
//SIGINT: 2: Ctrl + C: interept process and carrage return
//SIGQUIT: 3: Ctrl + \: exit shell
//SIGTERM: 15: Ctrl + D: ignore
void	sigint_handler(int	sig)
{
	printf("\b\bSIGINT!\n");
	exit(1);
}

void	sigquit_handler(int	sig)
{
	printf("SIGQUIT!\n");
	exit(130);
}

void	sigterm_handler(int	sig)
{
	printf("\b\bSIGTERM!\n");
}

void	multi_sig_handler_child(int sig_n)
{
	if (sig_n == 2)
		sigint_handler(sig_n);
	else if (sig_n == 3)
		sigquit_handler(sig_n);
	else if (sig_n == 15)
		sigterm_handler(sig_n);
}
