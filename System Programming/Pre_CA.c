#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


void child_handler(int signum) {
    printf("Child process received signal %d\n", signum);
}

int main() {
    pid_t pid;
    int status;


    pid = fork(); // create child process

    if (pid == 0) { // child process
        printf("Child process waiting for signal...\n");
        signal(SIGUSR1, child_handler); // set up signal handler for child process

        while (1) {
            sleep(1); // wait for signal
        }
        exit(0);
    } else if (pid > 0) { // parent process
        printf("Parent process sending signal to child...\n");
        kill(pid, SIGUSR1); // send signal to child process
        wait(&status); // wait for child process to terminate
        printf("Child process terminated with status %d\n", status);
    } else { // error
        fprintf(stderr, "Fork error\n");
        exit(1);
    }

    return 0;
}