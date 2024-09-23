// Roll Num : MT2024137
// Name : Shah Mohit P
// 32. Write a program to implement semaphore to protect any critical section.
// a. rewrite the ticket number creation program using semaphore
// b. protect shared memory from concurrent write access
// c. protect multiple pseudo resources ( may be two) using counting semaphore
// d. remove the created semaphore
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>

int main(){
    int fd;
    struct{
        int ticket_no;
    }db;

    db.ticket_no = 2;

    fd = open("db", O_CREAT|O_RDWR, 0744);
    write(fd, &db, sizeof(db));
    close(fd);
    fd = open("db", O_RDONLY);
    read(fd, &db, sizeof(db));
    printf("Ticket Number : %d\n", db.ticket_no);
    close(fd);

}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 32a_Ticket_No.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Ticket Number : 2
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 32a_Ticket_sema.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Loading.... Wait a Minute
// Current Ticket Number : 2
// Enter to unlock

// Terminal 2:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Loading.... Wait a Minute