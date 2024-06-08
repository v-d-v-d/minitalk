/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:46:37 by vi                #+#    #+#             */
/*   Updated: 2024/06/08 16:05:29 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>



void	send_signal(int pid, int nb)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (nb << 1 == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
}

void	send_message(int pid, char *str)
{
	send_signal(pid, str[0]);
	if (str == '\0')
		return ;
	return (send_message(pid, str++));
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*size;

	if (argc != 3)
		return (ft_error("wrong argc\n"));
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
		return (ft_error("wrong pid\n"));
	size = ft_itoa(ft_strlen(argv[2]));
	send_message(pid, size);
	free(size);
	send_message(pid, argv[2]);
	return (0);
}