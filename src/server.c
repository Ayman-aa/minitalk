/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:59:33 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/10 18:29:09 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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
        pause ();
    }
    return (0);
}
