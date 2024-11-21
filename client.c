/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:41:26 by mmusic            #+#    #+#             */
/*   Updated: 2024/11/21 16:02:54 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_sig_received;

void    signal_handler(int sig, siginfo_t *info, void *ucontext)
{
    (void)ucontext;
    (void)info;
    if (sig == SIGUSR2)
        g_sig_received = 1;
}

void    send_bit(int pid, int sig)
{
    g_sig_received = 0;
    if (kill(pid, sig) == -1)
        exit(1);
    while (!g_sig_received)
        pause();
    usleep(50);
}

void    convert(int pid, char *str)
{
    int	i;
	int	temp;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			temp = (*str >> i) & 1;
			if (temp == 0)
				send_bit(pid, SIGUSR1);
			else
				send_bit(pid, SIGUSR2);
			usleep(100);
			i--;
		}
		str++;
	}
}

int	sanitize(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int main(int argc, char **argv)
{
    int	pid;
    struct sigaction sa;

    g_sig_received = 0;
	if (argc != 3)
		write(1, "enter server PID and one argument!\n", 35);
	if (!sanitize(argv[1]))
		return (write(1, "Server PID wrong!\n", 18), 1);
	pid = ft_atoi(argv[1]);
    sa.sa_sigaction = signal_handler;
    sigaction(SIGUSR2, &sa, NULL);
    convert(pid, argv[1]);
    
}