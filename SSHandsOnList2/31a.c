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

    key_t key = ftok(".", 'a');

    int semid = semget(key, 1, IPC_CREAT | 0744); //Creating the semaphore an dgetting its id
    //Second argument shows what should be the size of array of semaphore
    
    buff.val = 1; //here 1 is given to create a binary semaphore
    semctl (semid, 0, SETVAL, buff); //Setting the value in the Semaphore created
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 31a.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -s

// ------ Semaphore Arrays --------
// key        semid      owner      perms      nsems     
// 0x610500de 0          mohit      744        1     