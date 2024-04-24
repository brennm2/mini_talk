/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:16:58 by bde-souz          #+#    #+#             */
/*   Updated: 2024/04/02 15:14:19 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_talk.h"

void	signal_hendler(int signum)
{
	static unsigned char	c;
	static int				bit_position;
	unsigned char			*str;

	c |= (signum == SIGUSR1);
	bit_position++;
	if (bit_position == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		bit_position = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("\nServer PID: %d\n\n", getpid());
	while (1)
	{
		signal(SIGUSR1, signal_hendler);
		signal(SIGUSR2, signal_hendler);
	}
	return (0);
}
