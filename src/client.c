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

void	send_signal(int server_pid, unsigned char octet)
{
	int				i;
	unsigned char	octet_tmp;

	i = 8;
	octet_tmp = octet;
	while (i > 0)
	{
		i--;
		octet_tmp = octet >> i;
		if (octet_tmp % 2 == 0)
		{
			kill(server_pid, SIGUSR2);
		}
		else
		{
			kill(server_pid, SIGUSR1);
		}
		usleep(10);
	}
}

int main(int argc, char **argv) 
{
	int		server_pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("The parameters entered are incorrect.\n");
		return(0);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i] != '\0')
	{
		send_signal(server_pid, (unsigned char)message[i]);
		i++;
	}
	send_signal(server_pid, 0);
	return (0); 
}
