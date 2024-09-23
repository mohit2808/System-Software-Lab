// Roll Num : MT2024137
// Name : Shah Mohit P
// 30. Write a program to create a shared memory.
// a. write some data to the shared memory
// b. attach with O_RDONLY and check whether you are able to overwrite.
// c. detach the shared memory
// d. remove the shared memory
#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

int main(){
    // int key = ftok(".", 'f');
    // int shmid = shmget(key, 200, IPC_CREAT | 0744); //Created a shm 

    // printf("shmid : %d\n", shmid); //id got in output is 4227125

    shmctl(4227125, IPC_RMID, NULL); //Deleting the shared memory
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 30d.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// shmid : 4227125
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -m
// ------ Shared Memory Segments --------
// key        shmid      owner      perms      bytes      nattch     status
// 0x660500de 4227125    mohit      744        200        0                       
// 0x640500de 3932221    mohit      774        1024       0               

// After adding delete statement:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 30d.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -m
// ------ Shared Memory Segments --------
// key        shmid      owner      perms      bytes      nattch     status  
// 0x640500de 3932221    mohit      774        1024       0             