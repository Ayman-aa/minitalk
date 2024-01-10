/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaamam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:20:45 by aaamam            #+#    #+#             */
/*   Updated: 2024/01/10 13:20:47 by aaamam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
// Global variables to store the current character and its bit position
static int current_char = 0;
static int bit_position = 0;

void signal_handler(int signum) {
    // Shift the current character to the left to make room for the new bit
    current_char <<= 1;
    // If the signal is SIGUSR1, set the least significant bit of the current character to 1
    if (signum == SIGUSR1) {
        current_char |= 1;
    }
    // Increment the bit position
    bit_position++;
    // If we've received 8 signals, print the character (unless it's the null character) and reset the current character and bit position
    if (bit_position == 8) {
        if (current_char != '\0') {
            putchar(current_char);
        } else {
            putchar('\n'); // Print a newline character when the null character is received
        }
        fflush(stdout); // Ensure the characters are immediately printed
        current_char = 0;
        bit_position = 0;
    }
}
int main() {
    printf("My PID is: %d\n", getpid());

    // Set up the signal handler
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    

    // Wait for signals
    while (1) {
        pause();
    }

    return 0;
}
