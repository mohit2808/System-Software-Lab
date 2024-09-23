// Roll Num : MT2024137
// Name : Shah Mohit P
//28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>

int main(){
    struct msqid_ds buff;

    msgctl(0, IPC_STAT, &buff);

    printf("Current Permission : %o\n", buff.msg_perm.mode & 0777);

    //Setting new permission
    buff.msg_perm.mode = (buff.msg_perm.mode & ~0777) | 0764;

    //Passing the changes of structure to the queue
    msgctl(0, IPC_SET, &buff);

    printf("New Permissions of queue is : %o\n", buff.msg_perm.mode & 0777);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -q

// ------ Message Queues --------
// key        msqid      owner      perms      used-bytes   messages    
// 0x610500de 0          mohit      774        29           3           

// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 28.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Current Permission : 774
// New Permissions of queue is : 764
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -q

// ------ Message Queues --------
// key        msqid      owner      perms      used-bytes   messages    
// 0x610500de 0          mohit      764        29           3          