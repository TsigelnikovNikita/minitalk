#include <signal.h>
#include "../libft/libft.h"

typedef struct byte_s
{
    u_char byte;
    char bit;
} byte_t;

typedef struct sigaction sigaction_t;

byte_t g_byte;

void printPid()
{
    pid_t pid = getpid();
    ft_putstr_fd("Hello from the server!\n"
                 "Here is my pid to connect: ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
}

void byte_handler()
{
    g_byte.bit--;
    if (g_byte.bit < 0)
    {
        write(1, &g_byte.byte, 1);
        g_byte.bit = 7;
        g_byte.byte = 0;
    }
}

/**
 * SIGUSR1 = 0
 */
void sigusr1_handler(int signal, siginfo_t * info, void *unused)
{
    (void)signal;
    (void)unused;

    byte_handler();
    pid_t pid = info->si_pid;
    kill(pid, SIGUSR1);
}

/**
 * SIGUSR2 = 1
 */
void sigusr2_handler(int signal, siginfo_t * info, void *unused)
{
    (void)signal;
    (void)unused;

    g_byte.byte = g_byte.byte | (1 << g_byte.bit);
    byte_handler();
    pid_t pid = info->si_pid;
    kill(pid, SIGUSR2);
}

int main()
{
    sigaction_t sigaction_;

    g_byte.bit = 7;
    g_byte.byte = 0;

    ft_bzero(&sigaction_, sizeof(sigaction_t));
    sigaction_.sa_sigaction = sigusr1_handler;
    sigaction_.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sigaction_, 0);

    ft_bzero(&sigaction_, sizeof(sigaction_t));
    sigaction_.sa_sigaction = sigusr2_handler;
    sigaction_.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sigaction_, 0);

    printPid();
    while (1)
    {
        pause();
    }
    return 0;
}
