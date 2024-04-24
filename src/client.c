/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:27:49 by bde-souz          #+#    #+#             */
/*   Updated: 2024/04/02 15:12:22 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_talk.h"

void	send_info(int pid, char *str, int strlen)
{
	int				bit;
	unsigned char	temp_c;
	int				len_temp;

	len_temp = 0;
	bit = 8;
	temp_c = *(str);
	while (strlen >= len_temp)
	{
		while (bit > 0)
		{
			bit--;
			temp_c = *(str) >> bit;
			if (temp_c % 2 == 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(200);
		}
		bit = 8;
		str++;
		len_temp++;
	}
}

int	main(int ac, char **av)
{
	pid_t		server_pid;
	const char	*message;
	int			i;
	int			strlen;

	i = 0;
	if (ac != 3)
	{
		ft_printf("\n\nError!\n");
		ft_printf("To send message, use: %s <PID> <MESSAGE>\n\n\n", av[0]);
		exit (0);
	}
	else
	{
		server_pid = ft_atoi(av[1]);
		strlen = ft_strlen(av[2]);
		send_info(server_pid, av[2], strlen);
	}
	return (0);
}
