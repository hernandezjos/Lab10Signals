
/***************************************************************
 * @file recv_signal.c
 * @assignment CPE-2600 Lab 10 - Signals
 * @author Joey Hernandez
 * @section 111
 * @date 11/13/2026
 *
 * Run this program first: ./recv_signal
 * Then run: ./send_signal <PID shown by this program>
 ***************************************************************/
 
 #define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


void handle_usr1(int sig, siginfo_t *info, void *context) {

    (void)context;

    printf("Received SIGUSR1 (signal %d) from pid %d with value: %d\n", sig, info->si_pid, info->si_value.sival_int);
}

int main() {

    struct sigaction action;

    memset(&action, 0, sizeof(action));

    action.sa_sigaction = handle_usr1;   
    action.sa_flags = SA_SIGINFO;      
      // Checks si_value
    sigemptyset(&action.sa_mask);

    if (sigaction(SIGUSR1, &action, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("pid = %d\n", getpid());
    printf("./send_signal %d\n", getpid());

    // sleep until signal 
    while (1) {
        pause();
    }

    return 0;
}