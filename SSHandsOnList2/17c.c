// Roll Num : MT2024137
// Name : Shah Mohit P
// 17. Write a program to execute ls -l | wc.
// a. use dup
// b. use dup2
// c. use fcntl
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
    int fd[2];
    pipe(fd);

    if(fork() == 0){
        close(1);
        close(fd[0]);
        fcntl(fd[1], F_DUPFD, 0);
        execlp("ls", "ls", "-l", (char *)NULL);
    }

    else{
        close(0);
        close(fd[1]);
        fcntl(fd[0], F_DUPFD, 0);
        execlp("wc", "wc", (char *)NULL);
    }
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 17c.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
//      35     307    1699