/***************************************************************
 * @file send_signal.c
 * @assignment CPE-2600 Lab 10 - Signals
 * @author Joey Hernandez
 * @section 111
 * @date 11/13/2026
 *
 * Usage: ./send_signal <receiver_PID>
 ***************************************************************/

 #define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {

    // make sure 1 arg
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    // convert arg to a pid
    pid_t target = atoi(argv[1]);

    if (target <= 0) {
        fprintf(stderr, "Invalid pid: %s\n", argv[1]);
        return 1;
    }

    // rand number for each run
    srand(time(NULL));
    int number = rand();

    union sigval value;
    memset(&value, 0, sizeof(value));
    value.sival_int = number;

    printf("SIGUSR1 sending %d to pid %d\n", number, target);

    if (sigqueue(target, SIGUSR1, value) == -1) {
        perror("sigqueue");
        return 1;
    }

    return 0;
}
