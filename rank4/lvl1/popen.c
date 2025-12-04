/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:17:13 by roversch          #+#    #+#             */
/*   Updated: 2025/12/04 16:18:28 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const av[], int type)
{
	if (!file || !av || (type != 'r' && type != 'w'))
		return (-1);
	
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close (fd[1]);
		}
		if (type == 'w')
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
		}
		execvp(file, av);
		exit(1);
	}
	else
	{
		if (type == 'r')
		{
			close(fd[1]);
			return (fd[0]);
		}
		if (type == 'w')
		{
			close(fd[0]);
			return (fd[1]);
		}
	}
	return (-1);
}

#include <stdio.h>

int main(void)
{
    int  fd;

    fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	char line[100];
	read(fd, line, 100);
	printf("%s", line);
    return (0);
}