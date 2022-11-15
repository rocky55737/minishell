#include "minishell_builtin.h"
#include <unistd.h>


int	main(int ac, char **av, char **env)
{
	pwd(env);
	return (1);
}