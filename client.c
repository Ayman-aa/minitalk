/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:20:54 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/10 13:20:58 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// client.c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void send_string(int pid, char *str) {
    // Iterate over each character in the string, including the null character at the end
    for (size_t i = 0; i <= strlen(str); i++) {
        char c = str[i];
        // Iterate over each bit in the character
        for (int j = 7; j >= 0; j--) {
            // If the bit is 1, send SIGUSR1, otherwise send SIGUSR2
            if ((c >> j) & 1) {
                kill(pid, SIGUSR1);
            } else {
                kill(pid, SIGUSR2);
            }
            // Wait a short time to ensure the server has time to handle the signal
            usleep(100);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <PID> <string>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    char *str = argv[2];

    send_string(pid, str);

    return 0;
}
