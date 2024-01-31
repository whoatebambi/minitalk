/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:43 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/10 18:34:28 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

// static int	g_control;

// void    ft_control(int signal)
// {
//     if (signal == SIGUSR2)
// 		g_control = 1;
// }

void	send_signal(int pid, int c)
{
	static int	bit;

	// g_control = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit))) // if ((c << bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(42);
		bit++;
	}
	// while (g_control != 1)
	// 	pause();
	bit = 0;
}

int main(int argc, char **argv)
{
	int				pid;
	unsigned char	*message;

	if (argc != 3)
	{
		ft_printf("The parameters entered are incorrect.\n");
		return(0);
	}
	pid = ft_atoi(argv[1]);
	message = (unsigned char *)argv[2];
	// signal(SIGUSR2, ft_control);
	while (*message)
		send_signal(pid, *message++);
	send_signal(pid, '\0');
	return (0); 
}
