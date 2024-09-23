// Roll Num : MT2024137
// Name : Shah Mohit P
// 25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
// a. access permission
// b. uid, gid
// c. time of last message sent and received
// d. time of last change in the message queue
// d. size of the queue
// f. number of messages in the queue
// g. maximum number of bytes allowed
// h. pid of the msgsnd and msgrcv
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<time.h>

int main(){

    struct msqid_ds buff;

    msgctl(0, IPC_STAT, &buff); //using the message queue created in 24th program// The IPC_STAT copies information of msg queue in to the structure (here buff) 

    printf("Permissions of Queue : %o\n", buff.msg_perm.mode & 0777);
    printf("UID: %d\nGID: %d\n", buff.msg_perm.uid, buff.msg_perm.gid);
    printf("Last Message Sent: %s", ctime(&buff.msg_stime));
    printf("Last Message Received: %s", ctime(&buff.msg_rtime));
    printf("Last Change Time: %s", ctime(&buff.msg_ctime)); 
    printf("Current Queue Size (bytes): %lu\n", buff.__msg_cbytes); 
    printf("Number of Messages in Queue: %lu\n", buff.msg_qnum);   
    printf("Maximum Bytes Allowed: %lu\n", buff.msg_qbytes);
    printf("PID of Last msgsnd: %d\n", buff.msg_lspid);
    printf("PID of Last msgrcv: %d\n", buff.msg_lrpid);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 25.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Permissions of Queue : 774
// UID: 1000
// GID: 1000
// Last Message Sent: Thu Jan  1 05:30:00 1970
// Last Message Received: Thu Jan  1 05:30:00 1970
// Last Change Time: Fri Sep 20 14:14:59 2024
// Current Queue Size (bytes): 0
// Number of Messages in Queue: 0
// Maximum Bytes Allowed: 16384
// PID of Last msgsnd: 0
// PID of Last msgrcv: 0