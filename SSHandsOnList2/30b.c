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
    int key = ftok(".", 'e');
    int shmid = shmget(key, 1024, IPC_CREAT | 0774);//Creating the shm and getting its shmid

    printf("shmid : %d\n", shmid);

    char *data = (char *)shmat(shmid, NULL, SHM_RDONLY);//Attaching the Shm in the process space

    printf("Enter Some text : ");
    scanf("%[^\n]", data);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 30b.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// shmid : 4096010
// Enter Some text : Hello
// Segmentation fault (core dumped)