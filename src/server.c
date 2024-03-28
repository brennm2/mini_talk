/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:16:58 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/28 16:49:21 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_talk.h"


void	signal_hendler (int	signum)
{
	static int				i = 0;
	static unsigned char	c = 0;
	unsigned char *str;
	static int flag;

	if (flag == 0)
		str = ft_strdup("");
	if (signum == SIGUSR2)
		c = c << 1;
	else if (signum == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		str = ft_strjoin(str, &c);
		//ft_printf("server: %s\n", str);
		flag++;
		if (c == '\0')
		{
			ft_printf("END\n");
			str = ft_strjoin(str, "\0\n");
			ft_printf("%s", str);
			free(str);
			flag = 0;
		}
		i = 0;
		c = 0;
		//ft_printf("%c", c);
	}



	// static unsigned char	c;
	// static int				bit_position;
	// unsigned char *str;
	// static int flag;

	// if (flag == 0)
	// 	str = ft_strdup("");
	// c |= (signum == SIGUSR1);
	// bit_position++;
	// if (bit_position == 8)
	// {
	// 	if (c == '\0')
	// 	{
	// 		str = ft_strjoin(str, "\n");
	// 		ft_printf("%s", str);
	// 		free(str);
	// 		flag = 0;
	// 	}
	// 	else
	// 	{
	// 		str = ft_strjoin(str, &c);
	// 		flag++;
	// 	}
	// 	bit_position = 0;
	// 	c = 0;
	// }
	// else
	// 	c <<= 1;
}

int	main(void)
{
	ft_printf("\nServer PID: %d\n\n", getpid());
	while(1)
	{
		signal(SIGUSR1, signal_hendler);
		signal(SIGUSR2, signal_hendler);
	}
		//pause();
	return (0);
}