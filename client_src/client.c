#include <signal.h>
#include "../libft/libft.h"

void	sig_handler(int signal)
{
	(void) signal;
}

void	send_byte(pid_t pid, const char byte)
{
	t_byte		byte_s;

	byte_s.bit = 7;
	byte_s.byte = byte;
	while (1)
	{
		if ((byte_s.byte & 1 << byte_s.bit) >> byte_s.bit)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		byte_s.bit--;
		if (byte_s.bit == -1)
			break ;
		usleep(20);
	}
}

void	core(pid_t pid, const char *message)
{
	size_t		i;
	u_int32_t	second;

	i = 0;
	while (message[i] != 0)
	{
		send_byte(pid, message[i]);
		second = usleep(10000000);
		if (second == 0)
		{
			ft_putendl_fd("The connection to the server_src"
				 "was interrupted", 1);
			exit(1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*message;
	pid_t	pid;

	if (ac != 3)
	{
		ft_putendl_fd("Wrong number of arguments", 1);
		return (1);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	signal(SIGUSR1, sig_handler);
	core(pid, message);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("Message was received", 1);
	return (0);
}
