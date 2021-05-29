#include <signal.h>
#include "../libft/libft.h"

typedef struct byte_s
{
    u_char byte;
    u_char bit;
} byte_t;

void sig_handler(int signal)
{
    (void)signal;
}

void core(pid_t pid, const char *message)
{
    size_t i;
    byte_t byte;
    u_int32_t second;

    i = 0;
    while (message[i] != 0)
    {
        byte.bit = 7;
        byte.byte = message[i];
        while (1)
        {
            if ((byte.byte & 1 << byte.bit) >> byte.bit)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            if (byte.bit == 0)
                break;
            byte.bit--;
            second = usleep(1000);
            if (second == 0)
            {
                ft_putendl_fd("The connection to the server was interrupted", 1);
                exit(1);
            }
        }
        usleep(1000);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac != 3) {
        ft_putendl_fd("Wrong number of arguments", 1);
        return (1);
    }
    pid_t pid = ft_atoi(av[1]);
    char* message = av[2];
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
    core(pid, message);
    return (0);
}
