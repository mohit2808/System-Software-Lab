// Roll Num : MT2024137
// Name : Shah Mohit P
// 32. Write a program to implement semaphore to protect any critical section.
// a. rewrite the ticket number creation program using semaphore
// b. protect shared memory from concurrent write access
// c. protect multiple pseudo resources ( may be two) using counting semaphore
// d. remove the created semaphore
#include<sys/sem.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
    key_t key = ftok(".", 'd');
    int semid = semget(key, 1, 0);

    semctl(semid, 1, IPC_RMID);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -s

// ------ Semaphore Arrays --------
// key        semid      owner      perms      nsems     
// 0x610500de 0          mohit      744        1         
// 0x620500de 1          mohit      744        1         
// 0x630500de 2          mohit      744        3         
// 0x640500de 3          mohit      744        1         

// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 32d.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -s

// ------ Semaphore Arrays --------
// key        semid      owner      perms      nsems     
// 0x610500de 0          mohit      744        1         
// 0x620500de 1          mohit      744        1         
// 0x630500de 2          mohit      744        3   