// Roll Num : MT2024137
// Name : Shah Mohit P
// 31. Write a program to create a semaphore and initialize value to the semaphore.
// a. create a binary semaphore
// b. create a counting semaphore
#include<sys/sem.h>
#include<stdio.h>
#include<unistd.h>

union semun {
    int val;      // value for SETVAL 
    struct semid_ds *buf;  // buffer for IPC_STAT, IPC_SET
    unsigned short int *array;  // array for GETALL, SETALL   
};

int main(){
    union semun buff;

    key_t key = ftok(".", 'b');

    int semid = semget(key, 1, IPC_CREAT | 0744);
    
    buff.val = 2; //here 2 which is greater than 1 is given to create a counting semaphore
    semctl(semid, 0, SETVAL, buff); //Setting the value in the Semaphore created
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 31b.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -s

// ------ Semaphore Arrays --------
// key        semid      owner      perms      nsems     
// 0x610500de 0          mohit      744        1         
// 0x620500de 1          mohit      744        1     