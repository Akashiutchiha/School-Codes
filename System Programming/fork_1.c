//Creating a parent and a child process while sending a signal between them
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
    printf("hello world this line is running");
    pid_t cid;
    int status;
    cid = fork();

    if(cid == 0){
        printf("This is the child process");
        printf("waiting for the signal");
        while(1){
            sleep(1);
        }
        exit(0);

    }else if(cid > 0){
        printf("This is the parent process");
        wait(&status);

    }else{
        printf("Error, Child process not created");
    }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>

// int main(){
//     pid_t pid;
//     printf("Before fork (pid=%d)\n", getpid());
//     int x = 1;

//     pid = fork();
//     if(pid == 0){
//         sleep(5);
//         printf("child: id=%d\n", pid);
//                 printf("child: pid=%d\n", getpid());

//         printf("parents PID: x=%d\n", getppid());
//         exit(0);
//     }else if(pid < 0){
//         perror("fork");
//         exit(1);
//     }else{
//         printf("parent: pid=%d\n", pid);
//         exit(0);
//         }

//         return 0;
// }
