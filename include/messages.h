/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:56:24 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/10 17:03:14 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define C_ERROR "\n\033[0;91mError !\033[0m"
# define C_ARGS "\033[38;5;214mAdd the server PID and a string.\033[0m"
# define C_EX_ARGS "\033[0;92mExample : ./client PID) (Message)\033[0m\n"

# define C_NOTIFICATION "\033[0;90mWaiting for notification...\033[0m\n"

# define S_PID "\033[0;96mMy PID : [%d], parameter for the client.\033[0m\n\n"
# define S_WLC "\n\033[0;94mI print messages sent by the client.\033[0m\n"
# define S_CHEV "\033[0;90m>>\033[0m "

# define NOTIFICATION_R1 "\033[0;91mR\033[38;5;214mE\033[0;93mC\033[0;92mE"
# define NOTIFICATION_R2 "\033[0;96mI\033[0;94mV\033[0;95mE\033[0;97mD\033[0m\n"

# define SA_USR1_FAIL "SIGUSR1 failed\n"
# define SA_USR2_FAIL "SIGUSR2 failed\n"

# define SERV_FAIL_USR1 "SIGUSR1"
# define SERV_FAIL_USR2 "Server failed to send SIGUSR2"

# define UNICODE "\033[0;90m(Undefined with unicode...)\033[0m\n"

#endif