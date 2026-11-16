/***************************************************************
 * @file signal_sigaction.c
 * @assignment CPE-2600 Lab 10 - Signals
  * @author Joey Hernandez
 * @section 111
 * @date 11/13/2026
 *
 *
 * From another terminal, run: kill -SIGUSR1 <PID>
 ***************************************************************/

 #define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief SA_SIGINFO-style handler for SIGUSR1 - prints the sender's pid
 * @param sig the signal number that was received
 * @param info details about the signal, including the sender's pid
 * @param context the interrupted context (unused)
 */

void handle_usr1(int sig, siginfo_t *info, void *context) {
    (void)context;
    printf("SIGUSR1 (signal %d) recieved from process %d\n", sig, info->si_pid);
}

int main() {
    struct sigaction action;

    memset(&action, 0, sizeof(action));
    action.sa_sigaction = handle_usr1;   
    action.sa_flags = SA_SIGINFO;        // required to receive siginfo_t
    sigemptyset(&action.sa_mask);        // block no extra signals 

    if (sigaction(SIGUSR1, &action, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("signal_sigaction running: pid = %d\n", getpid());
    printf("Send signal: kill -SIGUSR1 %d\n", getpid());

    //sleep until signal 
    while (1) {
        pause();
    }

    return 0;
}
