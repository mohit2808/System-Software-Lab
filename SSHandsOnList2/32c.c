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

// struct sembuf {
//     short sem_num;  /* semaphore number: 0 means first */
//     short sem_op;   /* semaphore operation: lock or unlock */
//     short sem_flg;   /* operation flags : 0, SEM_UNDO, IPC_NOWAIT */
// };

int main(){
    key_t key = ftok(".", 'b');
    int semid = semget(key, 1, 0); //Using the semaphore created in 31b program

    struct sembuf buff = {0, -1, 0}; //Assing the values to the sembuff structure provided above
    //Above -1 is given to decrease the value of semaphore(-1 + previous value)
    
    printf("Before Entering the Critical Section\n");
    printf("Waiting for Unlock....\n");
    
    semop(semid, &buff, 1); //Passing the information to the semaphore

    printf("You are inside the critical section\n");
    printf("Enter to unlock\n");
    getchar();

    buff.sem_op = 1; //Incrementing the semaphore value 
    semop(semid, &buff, 1); //Passing the information to the semaphore
}

//OUTPUT [Here we would be able to enter the critical section with 2 process and 3rd will wait cause semaphore was initialized with 2] 

// Terminal 1:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 32c.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Before Entering the Critical Section
// Waiting for Unlock....
// You are inside the critical section
// Enter to unlock

// Terminal 2:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 32c.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Before Entering the Critical Section
// Waiting for Unlock....
// You are inside the critical section
// Enter to unlock


// Terminal 3:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 32c.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Before Entering the Critical Section
// Waiting for Unlock....

