#include "minitalk.h"

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
		usleep(42); // comment it for testing
	}
}

int main(int argc, char **argv) 
{
	int		server_pid;
	char	*message;
	int		i;

	// char	letter;
	// letter = 'a';
	// printf("%d\n", ft_toupper(letter));
	// printf("%d\n", letter);
	if (argc != 3)
	{
		printf("The parameters entered are incorrect.\n");
		return(0);
	}
	server_pid = atoi(argv[1]);
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
