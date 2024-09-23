// Roll Num : MT2024137
// Name : Shah Mohit P
// 24. Write a program to create a message queue and print the key and message queue id.
#include<sys/msg.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<unistd.h>

int main(){
    int msgid;
    key_t key = ftok(".", 'a'); //This function creates key with the help of 1st argument path name and 2nd argument here is aski value of a[any positive value]

    msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0774); //this creates message queue and returns the msg id
    printf("Value of key : %d\n", key);
    printf("Value of key in Hexa Decimal : 0x%0x\n", key);
    printf("Message id of the message queue : %d\n", msgid);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 24.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Vakue of key : 1627717854
// Value of key in Hexa Decimal : 0x610500de
// Message id of the message queue : 0
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -q {this command gives info of currently existing msg queue which persits till reboot or deletion}

// ------ Message Queues --------
// key        msqid      owner      perms      used-bytes   messages    
// 0x610500de 0          mohit      774        0            0           