// Roll Num : MT2024137
// Name : Shah Mohit P
// 18. Write a program to find out total number of directories on the pwd.
// execute ls -l | grep ^d | wc ? Use only dup2.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int fd1[2];
    int fd2[2];

    pipe(fd1);//pipe 1
    pipe(fd2);//pipe 2

    if(fork() == 0){
        close(fd1[0]); //closing read end of pipe1
        close(fd2[0]); //closing read end of pipe2
        close(fd2[1]); //closing write end of pipe 2
        dup2(fd1[1], 1);  //providing write end of pipe1 as stdout    
        execlp("ls", "ls", "-l", (char *)NULL);
    }

    else{
        if(fork() == 0){
            close(fd1[1]); //closing write end of pipe1
            close(fd2[0]); //closing read end of pipe2
            dup2(fd1[0], 0); //giving the read end of of pipe 1 as stdin 
            dup2(fd2[1], 1); //giving the write end of pipe2 as stdout
            execlp("grep", "grep", "^d", (char *)NULL);
        }

        else{
            close(fd2[1]); //closing write end of pipe2
            close(fd1[0]); //closing read end of pipe1
            close(fd1[1]); //closing write end of pipe1
            dup2(fd2[0], 0); //providing read end of pipe2 as read end
            execlp("wc", "wc", (char *)NULL);
        }
    }
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 18.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
//       2      18     106