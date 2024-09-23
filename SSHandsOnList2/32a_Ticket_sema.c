// Roll Num : MT2024137
// Name : Shah Mohit P
// 32. Write a program to implement semaphore to protect any critical section.
// a. rewrite the ticket number creation program using semaphore
// b. protect shared memory from concurrent write access
// c. protect multiple pseudo resources ( may be two) using counting semaphore
// d. remove the created semaphore
#include<fcntl.h>
#include<sys/sem.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    struct{
        int ticket_no;
    }db;

    key_t key = ftok(".", 'f');
    int semid = semget(key, 1, IPC_CREAT | 0744);
   
    struct sembuf buff = {0, -1, 0};
    printf("Loading.... Wait a Minute\n");
    semop(semid, &buff, 1);

    int fd = open("db", O_RDWR);

    read(fd, &db, sizeof(db));

    printf("Current Ticket Number : %d\n", db.ticket_no);

    db.ticket_no++;
    lseek(fd, 0L, SEEK_SET);// Getting the cursor to the start of the file which moved at last because of the previous read

    printf("Enter to unlock\n");
    write(fd, &db, sizeof(db));
    getchar();

    buff.sem_op = 1; //Incrementing the semaphore value 
    semop(semid, &buff, 1); //Passing the information to the semaphore
    printf("Unlocked\n");

    return 0;
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