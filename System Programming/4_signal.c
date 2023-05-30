#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

static void display_message(int signo){
    printf("Generated Signal Alarm");
    alarm(2);
        
}

int main(void){
    signal(SIGALRM, display_message);
    while (1)
    {
        /* code */
    }
    
}