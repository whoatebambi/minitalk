#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h> // atoi


void	send_signal(int pid, unsigned char octet)
{
	int				i;
	unsigned char	octet_tmp;

	i = 8;
	octet_tmp = octet;
	while (i-- > 0)
	{
		// i--;
		octet_tmp = octet >> i;
		if (octet_tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100); // comment it for testing
	}
}

int main(int argc, char **argv) 
{ 
	int		pid;
	char	*str;
	int		i;

	if (argc != 3)
	{
		printf("The parameters entered are incorrect.\n");
		return(0);
	}

	pid = atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		send_signal(pid, (unsigned char)str[i]); //cast to unsigned char
		i++;
	}
	printf("Number of characters written: %d\n", i);

	return (0); 
} 
