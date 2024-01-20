#include "minitalk.h"

void	handle_signal(int signal)
{
	static unsigned char	character;
	static int				bit_position;
	int						bit_value;

	if (signal == SIGUSR1)
		bit_value = 1;
	else
		bit_value = 0;

	// Shift the character to the left by 1 and set the least significant bit
	character <<= 1;
	character |= bit_value;

	// Increment the bit position counter
	bit_position++;

	// Check if we have reconstructed a full character (8 bits)
	if (bit_position == 8)
	{
		if (character == 0)
	 		printf("\n");
		else
			printf("%c", character);	// Print the reconstructed character
		bit_position = 0;	// Reset for the next character
		character = 0;	// Reset the character
	}
}

int main(void) 
{	
	// struct sigaction sa;
	// sa.sa_handler = &handle_signal;
	// sigemptyset(&sa.sa_mask);
	// sa.sa_flags = SA_RESTART; // This flag can help with handling interrupted system calls

	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);

	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	printf("Server PID: %d\n", getpid());	
	while (1)
		pause();
	return (0); 
} 
