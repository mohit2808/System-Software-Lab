// Roll Num : MT2024137
// Name : Shah Mohit P
// 27. Write a program to receive messages from the message queue.
// a. with 0 as a flag
// b. with IPC_NOWAIT as a flag
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>

int main(){
    char buff[50];

    struct msgbuf{
        long int mtype;
        char mtext[50];
    }mq;

    msgrcv(0, &mq, 50, 6, IPC_NOWAIT); //After this the message of type 6 will be removed from the queue and copy in the mtext
    //IPC_NOWAIT returns imediately if no message is found of that type
    printf("Message of type 6 in the queue is : ");

    printf("%s\n", mq.mtext);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 27b.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Message of type 6 in the queue is : 