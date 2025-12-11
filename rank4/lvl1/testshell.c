#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int	picoshell(char **cmds[])
{
	int	i = 0;
	int	fd[2];
	int	last_fd = -1;
	int	ret = 0;
	pid_t pid;
	int status;

	while (cmds[i])
	{
		if (cmds[i + 1])
			pipe(fd);
		pid = fork();
		if (pid == -1)
		{
			if (cmds[i + 1])
			{
				close(fd[0]);
				close(fd[1]);
			}
			return (1);
		}
		if (pid == 0)
		{
			if (last_fd != -1)
			{
				dup2(last_fd, STDIN_FILENO);
				close(last_fd);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		else
		{
			if (last_fd != -1)
				close(last_fd);
			if (cmds[i + 1])
			{
				close(fd[1]);
				last_fd = fd[0];
			}
		}
		i++;
	}
}