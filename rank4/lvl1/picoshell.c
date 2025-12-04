/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picoshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:24:14 by roversch          #+#    #+#             */
/*   Updated: 2025/12/04 16:21:42 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			i++;
		}
	}
	while (wait(&status) > 0)
	{
		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
			ret = 1;
	}
	return (ret);
}

int main(void)
{
	char *cmd1[] = {"ls", "-l", NULL};
	char *cmd2[] = {"grep", "main", NULL};
	char *cmd3[] = {"wc", "-l", NULL};
	char **cmds[] = {cmd1, cmd2, cmd3, NULL};

	int status = picoshell(cmds);
	return 0;
}