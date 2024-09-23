// Roll Num : MT2024137
// Name : Shah Mohit P
//15. Write a simple program to send some data from parent to the child process.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
    int fd[2];
    char buff[19];

    pipe(fd);

    if(fork() == 0){
        close(fd[1]);//Closing the write end of pipe
        printf("CHILD\n");
        read(fd[0], buff, sizeof(buff));
        printf("Message got from parent:\n");
        printf("%s", buff);
    }

    else{
        close(fd[0]);//Closing the read end of pipe
        printf("PARENT\n");
        printf("Messaging the child\n");
        write(fd[1], "Hello from parent\n", 19);
        wait(0);
    }
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 15.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// PARENT
// Messaging the child
// CHILD
// Message got from parent:
// Hello from parent