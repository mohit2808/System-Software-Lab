// Roll Num : MT2024137
// Name : Shah Mohit P
// 26. Write a program to send messages to the message queue. Check $ipcs -q
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
    struct msgbuf{
        long int mtype;
        char mtext[50];
    }mq;

    printf("Enter the Type of Message to be sent: ");
    scanf("%ld", &mq.mtype);

    printf("Enter the Message: ");
    scanf(" %[^\n]", mq.mtext);

    int size = strlen(mq.mtext);

    msgsnd(0, &mq, size+1, 0);

}

// OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 26.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Enter the Type of Message to be sent: 5
// Enter the Message: Hello How are you
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -q

// ------ Message Queues --------
// key        msqid      owner      perms      used-bytes   messages    
// 0x610500de 0          mohit      774        20           3           

// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 26.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Enter the Type of Message to be sent: 6
// Enter the Message: This is message of type 6
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -q

// ------ Message Queues --------
// key        msqid      owner      perms      used-bytes   messages    
// 0x610500de 0          mohit      774        46           4  