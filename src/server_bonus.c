/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:53:10 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/11 18:00:49 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

/*	we use ft_btoa as signal handler when we recieve a signal
	if the signal is SIGUSR1 we use bitwise operation to 
	accumulate the bits recieved in 'int i' when 8 bits are 
	recieved and we reached the end of the transmition
	we print the character and we send a signal back
	to the client which is sender process
	we identify its id by using siginfo.si_pid tha contains
	the pid of the client then we send a SIGUSR2 back to the
	client */
void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == 0)
			kill(info->si_pid, SIGUSR2);
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

/*  We obtain the process ID (PID) of the server using
 	getpid() and print it to the console.
    Then, we set ft_btoa as the signal handler function
	for SIGUSR1 and SIGUSR2.
    The following line, sigemptyset(&act.sa_mask), ensures
	that the signal mask is cleared, allowing the signal 
	handler to run without blocking any other signals.
    Essentially, it allows all signals to be processed 
	during the execution of the signal handler.
    Once everything is set up, we are ready to handle 
	incoming SIGUSR1 and SIGUSR2 signals
    that are received by the server. */
int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("%s\n", C_ERROR);
		return (1);
	}
	pid = getpid();
	ft_printf(S_PID, pid);
	act.sa_sigaction = ft_btoa;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
