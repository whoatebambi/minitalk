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

void	handle_signal(int signal)
{
	static unsigned char	character;
	static int				bit_position;
	int						bit_value;

	if (signal == SIGUSR1)
		bit_value = 1;
	else
		bit_value = 0;

	character <<= 1;
	character |= bit_value;
	bit_position++;
	if (bit_position == 8)
	{
		if (character == 0)
	 		ft_printf("\n");
		else
			ft_printf("%c", character);
		bit_position = 0;
		character = 0;
	}
}

int main(void) 
{	
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	ft_printf("Server PID: %d\n", getpid());	
	while (1)
		pause();
	return (0); 
} 
