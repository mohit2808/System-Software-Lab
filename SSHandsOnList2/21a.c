// Roll Num : MT2024137
// Name : Shah Mohit P
//21. Write two programs so that both can communicate by FIFO -Use two way communications.
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){
    int fd1, fd2;
    char buff[50];

    fd1 = open("fifotest2", O_RDWR);
    write(fd1, "Hello from program 21a", 23);

    fd2 = open("fifotest3", O_RDWR);
    read(fd2, buff, sizeof(buff));

    printf("Response of 21b : %s\n", buff);
}

//OUTPUT
// Terminal 1:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 21a.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Response of 21b : Hello I am program 21b

// Terminal 2:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 21b.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Message from program 21a: Hello from program 21a
// Your Response : Hello I am program 21b