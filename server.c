/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:19:24 by vi                #+#    #+#             */
/*   Updated: 2024/07/21 01:18:19 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	stock(char **str1, char c)
{
	char	*srtnew;
	char	str2[2];

	str2[0] = c;
	str2[1] = '\0';
	srtnew = NULL;
	if (*str1 != NULL)
	{
		srtnew = ft_strdup (*str1);
		free(*str1);
	}
	if (srtnew == NULL)
		*str1 = ft_strjoin("", str2);
	else
		*str1 = ft_strjoin(srtnew, str2);
	if (*str1 != NULL)
		free(srtnew);
}

void	handler(int signo)
{
	static char	c = 0;
	static int	i = 0;
	static char	*str = NULL;

	if (signo == SIGUSR1)
		c = (c << 1) | 0b1;
	if (signo == SIGUSR2)
		c = c << 1;
	if (++i == 8)
	{
		i = 0;
		if (c == '\0')
		{
			if (str != NULL)
				ft_putstr_fd(str, STDOUT_FILENO);
			free(str);
			str = NULL;
			c = 0;
			return ;
		}
		stock(&str, c);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	ft_bzero(&act, sizeof(struct sigaction));
	act.sa_handler = &handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &act, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
