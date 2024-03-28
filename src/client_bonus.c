/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:27:49 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/25 16:29:58 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_talk.h"
#include <bits/types/siginfo_t.h>

void	send_info(int pid, unsigned char c)
{
	int	bit;
	unsigned char	temp_c;

	bit = 8;
	temp_c = c;
	while(bit > 0)
	{
		bit--;
		temp_c = c >> bit;
		if(temp_c % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
	}
}


int	main (int ac, char **av)
{
	pid_t	server_pid;
	const char	*message;
	int	i;
	
	i = 0;
	if (ac != 3)
	{
		ft_printf("\n\nError!\n");
		ft_printf("To send message, use: %s <PID> <MESSAGE>\n\n\n", av[0]);
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	message = av[2];
	
	while (message[i])
	{
		send_info(server_pid, message[i]);
		i++;
	}
	send_info(server_pid, '\0');
	return (0);
}