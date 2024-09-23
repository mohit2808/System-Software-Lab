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
    int key = ftok(".", 'd');
    int shmid = shmget(key, 1024, IPC_CREAT | 0774);//Creating the shm and getting its shmid

    printf("shmid : %d\n", shmid);

    char *data = (char *)shmat(shmid, NULL, 0);//Attaching the Shm in the process space

    printf("Enter Some text : ");
    scanf("%[^\n]", data);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 30a.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// shmid : 3932221
// Enter Some text : hello

// mohit@mohit-14IRL8:~/SSHandsOnList2$ ipcs -m
// ------ Shared Memory Segments --------
// key        shmid      owner      perms      bytes      nattch     status 
// 0x640500de 3932221    mohit      774        1024       0              
