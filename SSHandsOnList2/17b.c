// Roll Num : MT2024137
// Name : Shah Mohit P
// 17. Write a program to execute ls -l | wc.
// a. use dup
// b. use dup2
// c. use fcntl
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int fd[2];
    pipe(fd);

    if(fork() == 0){
        close(fd[0]);
        dup2(fd[1], 1);
        execlp("ls", "ls", "-l", (char *)NULL);
    }

    else{
        close(fd[1]);
        dup2(fd[0], 0);
        execlp("wc", "wc", (char *)NULL);
        //wait(0);
    }
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 17b.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
//      34     298    1649