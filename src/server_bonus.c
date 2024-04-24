/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:16:58 by bde-souz          #+#    #+#             */
/*   Updated: 2024/04/05 10:29:02 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_talk.h"

void	signal_hendler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit_position;

	(void)context;
	c |= (signum == SIGUSR1);
	bit_position++;
	if (bit_position == 8)
	{
		if (c == '\0')
		{
			kill(info->si_pid, SIGUSR2);
			ft_printf("\n");
		}
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
	struct sigaction	sa;

	sa.sa_sigaction = &signal_hendler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("\nServer PID: %d\n\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
