/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:59:33 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/12 19:24:49 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/*	we use ft_btoa as signal handler when we recieve a signal
	if the signal is SIGUSR1 we use bitwise operation to 
	accumulate the bits recieved in 'int i' when 8 bits are 
	recieved and we reached the end of the transmition
	we print the character */
void	ft_btoa(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

/* 	We retrieve the process ID (PID) of the server using 
	getpid() and display it on the console.
	Next, we set up ft_btoa as the signal handler
	function for both SIGUSR1 and SIGUSR2.
    The server enters an infinite loop using 
	while (argc == 1), continuously waiting for incoming signals.
    Upon receiving SIGUSR1, ft_btoa accumulates bits and prints 
	the corresponding character when 8 bits are collected.
    This process repeats, allowing the server to handle multiple 
	incoming signals without blocking.
    The pause() function suspends the server until a signal is received.
*/
int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("%s\n", C_ERROR);
		return (1);
	}
	pid = getpid();
	ft_printf(S_PID, pid);
	while (argc == 1)
	{
		if (signal(SIGUSR1, ft_btoa) == SIG_ERR)
		{
			ft_printf("%s\n", SA_USR1_FAIL);
			exit(EXIT_FAILURE);
		}
		if (signal(SIGUSR2, ft_btoa) == SIG_ERR)
		{
			ft_printf("%s\n", SA_USR2_FAIL);
			exit(EXIT_FAILURE);
		}
		pause();
	}
	return (0);
}
