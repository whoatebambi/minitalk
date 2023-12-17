#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	handle_signal(int signal)
{
	static unsigned char	character;
	static int				i;

	// i = 0;
	character |= (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		printf("%c", character);
		i = 0;
		character = 0;
	}
	else
		character <<= 1;
}

int main(void) 
{ 
	printf("Server PID: %d\n", getpid());
	
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);

	while (1)
	{
		pause();
	}

	return (0); 
} 

