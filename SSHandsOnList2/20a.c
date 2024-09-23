// Roll Num : MT2024137
// Name : Shah Mohit P
//20. Write two programs so that both can communicate by FIFO -Use one way communication
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    int fd = open("fifotest1", O_RDWR);
    char buff[30];

    write(fd, "Hello from program 20a", 23);
}

//OUTPUT
//Terminal 1:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 20a.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out

//Terminal2:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 20b.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Message from 20a : Hello from program 20a