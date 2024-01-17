/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:20:54 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/12 19:20:55 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/*	we use ft_atoi to convert the ascii value of the pid to 
	an integer value to print it and to use it later when we try
 	to send the signal to the server	*/
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

/*	we use ft_atob to read an ascii value of the 
	character c (av[1][i]) as bit a value that consist
	either of 1 or 0 and send these values with
	signal SIGUSR1 if its set or SIGUSR2 if it isn't 
	we use what we call  a bitwise operation to shift
	from a bit to another from left direction then
	sending using the kill() function.
	usleep() to set a delay between each sent signal 
	so we ensure that the server will get the correct values	*/
void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
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
		usleep(80);
		bit++;
	}
}

/*	we get the pid and the message entered by the user
	and we send each one of the characters to the server
	in the case of none of the conditions are met 
	we print error messages */
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
