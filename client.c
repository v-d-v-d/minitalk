/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:46:37 by vi                #+#    #+#             */
/*   Updated: 2024/07/21 00:55:43 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sys/wait.h>

void	send_signal(int pid, int nb)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((nb & 0b10000000) == 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		nb = nb << 1;
		i++;
		usleep(500);
	}
}

void	send_message(int pid, char *str)
{
	send_signal(pid, str[0]);
	if (str[0] == '\0')
		return ;
	return (send_message(pid, str + 1));
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
		return (ft_error("wrong argc\n"));
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
		return (ft_error("wrong pid\n"));
	send_message(pid, argv[2]);
	return (0);
}



