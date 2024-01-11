/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:52:14 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/11 17:58:42 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void confirm_msg(int signal)
{
    if (signal == SIGUSR2)
        ft_printf("%s%sMessage received%s\n", NOTIFICATION_R1, NOTIFICATION_R2, COLOR_RESET);
}

static int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
        if (c & (0x01 << bit))
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                ft_printf("%s\n", C_ERROR);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
            {
                ft_printf("%s\n", C_ERROR);
                exit(EXIT_FAILURE);
            }
        }
		usleep(400);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_atob(pid, argv[2][i]);
			i++;
		}
        signal(SIGUSR2, confirm_msg);
		ft_atob(pid, '\0');
	}
	else
	{
		ft_printf("%s\n", C_ERROR);
        ft_printf("%s\n", C_ARGS);
        ft_printf("%s\n", C_EX_ARGS);
		return (1);
	}
	return (0);
}
