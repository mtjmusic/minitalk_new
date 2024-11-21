/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:41:31 by mmusic            #+#    #+#             */
/*   Updated: 2024/11/21 15:57:06 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
# include <signal.h>

/* void signal_handler(int sig, siginfo_t *info, void *ucontext)
{
    (void)ucontext;
    if (sig == SIGUSR1)
        printf("SIGUSR1 from %d\n", info->si_pid);
    if (sig == SIGUSR2)
        printf("SIGUSR1 from %d\n", info->si_pid);
} */
void	reset(char *c, unsigned int *len)
{
	*c = 0;
	*len = 0;
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char			c = 0;
	static unsigned int	len = 0;
	static pid_t		client_pid = 0;

	(void)context;

	if (client_pid == 0)
		client_pid = info->si_pid;

	if (sig == SIGUSR1)
		c <<= 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 1;
	len++;
    kill(client_pid, SIGUSR2);
	if (len == 8)
	{
		write(1, &c, 1);
		reset(&c, &len);
	}
}

int main()
{
    char *pid;
    struct sigaction sa;

    pid = ft_itoa(getpid());
    if(!pid)
        return(1);
    write(1, pid, ft_strlen(pid));
    write(1, "\n", 1);
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1)
        pause();
}