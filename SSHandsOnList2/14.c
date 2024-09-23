// Roll Num : MT2024137
// Name : Shah Mohit P
// 14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
// the monitor.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
    char buff[22];
    int fd[2];

    pipe(fd);

    write(fd[1], "Hello from write end\n",22); //writing on the write end of pipe
    read(fd[0], buff, sizeof(buff));//reading from the other end of pipe and coping in buffer

    printf("Read from pipe: %s\n", buff);

}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 14.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Read from pipe: Hello from write end

