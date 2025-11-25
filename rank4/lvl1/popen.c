/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:53:53 by roversch          #+#    #+#             */
/*   Updated: 2025/11/25 10:39:01 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const av[], int type)
{
	if(!file || !av || (type != 'r' && type !='w' ))
		return -1;

	int fd[2];
	if (pipe(fd) < 0)
		return -1;
	pid_t pid = fork();
	if (pid < 0)
	{
		close(fd[1]);
		close(fd[0]);
		return -1;
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
		}
		if (type == 'w')
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
		}
		close(fd[0]);
		close(fd[1]);
		execvp(file, av);
		exit (-1);
	}
	if (type == 'r') {
		close(fd[1]);
		return (fd[0]);
	}
	if (type == 'w')
	{
		close(fd[0]);
		return (fd[1]);
	}
}