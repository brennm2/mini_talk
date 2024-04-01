/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:27:49 by bde-souz          #+#    #+#             */
/*   Updated: 2024/04/01 14:24:01 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_talk.h"

void	send_info(int pid, char *str, int strlen)
{
	int	i;
	int	c;
	int	len_temp;
	int	temp;

	i = 0;
	temp = 0;
	len_temp = 0;
	while (strlen >= len_temp)
	{
		c = *str;
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			if (i == 8)
			{
				temp++;
				printf("temp: %d\n", temp);
				
			}
			if (temp == 100)
			{
				printf("\n\n%d\n\n", temp);
				temp = 0;
				usleep(500);
			}
			else
				usleep(200);
		}
		//temp = 0;
		str++;
		i = 0;
		len_temp++;
	}
	// int	bit;
	// unsigned char	temp_c;

	// bit = 8;
	// temp_c = *(str);
	// while (*str)
	// {
	// 	while(bit > 0)
	// 	{
	// 		bit--;
	// 		temp_c = *(str) >> bit;
	// 		if(temp_c % 2 == 0)
	// 			kill(pid, SIGUSR2);
	// 		else
	// 			kill(pid, SIGUSR1);
	// 		usleep(200);
	// 	}
	// 	ft_printf("Client: %s\n", *str);
	// 	bit = 0;
	// 	str++;
	// }
}

int	main (int ac, char **av)
{
	char	*str;
	int		strlen;

	
	if (ac != 3)
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Format: [./client <SERVER ID (PID)> <STRING>]\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		str = ft_strjoin(av[2], "");
		strlen = ft_strlen(str);
		send_info(ft_atoi(av[1]), str, strlen);
		//printf("%c", str[2]);

		//send_info(ft_atoi(av[1]), '\0');
		
	}
	return (0);

	// pid_t	server_pid;
	// const char	*message;
	// int	i;
	
	// i = 0;
	// if (ac != 3)
	// {
	// 	ft_printf("\n\nError!\n");
	// 	ft_printf("To send message, use: %s <PID> <MESSAGE>\n\n\n", av[0]);
	// 	exit (0);
	// }
	// server_pid = ft_atoi(av[1]);
	// message = av[2];
	
	
	// send_info(server_pid, av[2]);
	// // while (message[i])
	// // {
	// // 	send_info(server_pid, message[i]);
	// // 	i++;
	// // }
	// //send_info(server_pid, '\0');
	// return (0);
}
