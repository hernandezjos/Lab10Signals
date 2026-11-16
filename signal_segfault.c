/***************************************************************
 * @file signal_segfault.c
 * @assignment CPE-2600 Lab 10 - Signals
 * @author Joey Hernandez
 * @section 111
 * @date 11/13/2026
 *
 ***************************************************************/

 #define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGSEGV - prints a message and returns
 * @param sig the signal number that was received
 */

void handle_segfault(int sig) {
    printf("Segmentation fault recieved (SIGSEGV, signal %d)\n", sig);
}

int main (int argc, char* argv[]) {
 
    (void)argc;
    (void)argv;

    // for segmentation faults
    if (signal(SIGSEGV, handle_segfault) == SIG_ERR) {
        perror("segfault");
            return 1;
    }

    int* i = NULL;
    printf("Value of i: %d\n", *i);

    return 0;
}
