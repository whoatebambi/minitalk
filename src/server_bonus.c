/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:43 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/10 18:34:28 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	c;

	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		c += 1 << bit;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		kill(info->si_pid, SIGUSR2);
		if (c == '\0')
			ft_printf("\n");
		bit = 0;
		c = 0;
	}
}

int main(void) 
{	
	struct sigaction	sigact;

	sigact.sa_sigaction = handle_signal;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	ft_printf("Server PID: %d\n", getpid());	
	while (1)
	{
		sigaction(SIGUSR1, &sigact, NULL);
		sigaction(SIGUSR2, &sigact, NULL);
	}
} 
