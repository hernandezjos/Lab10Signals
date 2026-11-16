/***************************************************************
 * @file signal_handler.c
 * @assignment CPE-2600 Lab 10 - Signals
 * @author Joey Hernandez
 * @section 111
 * @date 11/13/2026
 *
 * Demonstrates handling SIGINT without exiting from the handler.
 * Run: ./signal_handler
 * Send SIGINT from another terminal: kill -SIGINT <PID>
 * End the program: kill -SIGKILL <PID>
 ***************************************************************/

 #define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and returns
 * @param sig the signal number that was received
 */

void handle_signal(int sig) {
    printf("Signal received (%d) \n", sig);
}

int main() {

    printf("signal_handler running: pid = %d\n", getpid());

    // signal register
    if (signal(SIGINT, handle_signal) == SIG_ERR) {
    perror("signal");
    return 1;
}

    // Wait until signal 
    while(1) {
        printf("Sleeping...\n");
        sleep(1);
    }

    return 0;
}
