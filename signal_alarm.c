/***************************************************************
 * @file signal_alarm.c
 * @assignment CPE-2600 Lab 10 - Signals
 * @author Joey Hernandez
 * @section 111
 * @date 11/13/2026
 *
 * Run: ./signal_alarm
 ***************************************************************/

 #define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static volatile sig_atomic_t alarm_fired = 0;

/**
 * @brief Signal handler for SIGALRM
 * @param sig the signal number received
 */

void handle_alarm(int sig) {
    printf("Received SIGALRM (signal %d) ALARM\n", sig);
    alarm_fired = 1;
}

int main() {
    // check register before reschedule
    if (signal(SIGALRM, handle_alarm) == SIG_ERR) {
        perror("alarm");
        return 1;
    }

    // alarm in 5
    alarm(5);
    printf("Alarm in 5 seconds\n");

    
    int seconds = 0;
    while (!alarm_fired) {
        printf("%d s\n", seconds);
        sleep(1);
        seconds++;
    }

    printf("Exiting...\n");
    return 0;
}
