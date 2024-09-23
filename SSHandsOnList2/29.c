// Roll Num : MT2024137
// Name : Shah Mohit P
//29. Write a program to remove the message queue.
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>

int main(){
    // key_t key = ftok(".", 'b');
    // int msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0744); //Creating the msg queue

    //Deleting the msg queue
    msgctl(1, IPC_RMID, NULL); //IPC_RMID flag does not required the msqid_ds structure
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -q

// ------ Message Queues --------
// key        msqid      owner      perms      used-bytes   messages    
// 0x610500de 0          mohit      764        29           3           
// 0x620500de 1          mohit      744        0            0           

// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 29.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -q

// ------ Message Queues --------
// key        msqid      owner      perms      used-bytes   messages    
// 0x610500de 0          mohit      764        29           3         