// Roll Num : MT2024137
// Name : Shah Mohit P
//22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
// system call with FIFO.
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    int fd = open("fifotest4", O_RDWR);
    char buff[30];

    printf("Enter text: ");
    scanf("%[^\n]", buff);

    write(fd, buff, sizeof(buff));
}

//OUTPUT
// Terminal 1:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 22a.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Enter text: 

// Terminal 2:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 22b.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Data is not available within 10 secs