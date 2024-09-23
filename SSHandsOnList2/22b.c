// Roll Num : MT2024137
// Name : Shah Mohit P
//22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
// system call with FIFO.
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>
#include<stdlib.h>

int main(){
    int fd, retval;
    char buff[50];
    fd_set rfds;
    struct timeval tv;

    fd = open("fifotest4", O_RDONLY);
    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    retval = select(fd+1, &rfds, NULL, NULL, &tv);
    if(retval) printf("Data Available\n");
    else{ 
        printf("Data is not available within 10 secs\n");
        exit(0);
    }

    read(fd, buff, sizeof(buff));
    printf("Text from Fifo: %s\n", buff);
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