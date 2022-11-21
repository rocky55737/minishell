#include <unistd.h>

int main(int ac, char **av, char **env)
{
	char	*cmd;
	char	*argv[4];

	cmd = "/bin/echo";
	argv[0] = "echo";
	argv[1] = "`ls -al ..`";
	argv[2] = 0;
    execve(cmd, argv, env); 
}