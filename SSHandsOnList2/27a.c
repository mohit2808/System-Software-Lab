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

    msgrcv(0, &mq, 50, 6, 0); //After this the message of type 6 will be removed from the queue and copy in the mtext
    //Here last argument ie flag argument is 0 therefore it will wait if no message of that type is found
    printf("Message of type 6 in the queue is : ");

    printf("%s\n", mq.mtext);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -q

// ------ Message Queues --------
// key        msqid      owner      perms      used-bytes   messages    
// 0x610500de 0          mohit      774        28           3           

// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 27.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Message of type 6 in the queue is : This is message of type 6
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -q

// ------ Message Queues --------
// key        msqid      owner      perms      used-bytes   messages    
// 0x610500de 0          mohit      774        2            2        