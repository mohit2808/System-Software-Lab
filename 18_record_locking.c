/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
 
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

struct{
    int record_num;
    int count;
}db;

int main(){
    
    int fd, input;

    fd = open("record.txt", O_RDWR);

    printf("Select Record Number : ");
    scanf("%d", &input);

    struct flock lock;

    lock.l_type = F_WRLCK; //for read lock give here F_RDLCK and it will allow the read locking for other processes
    lock.l_whence = SEEK_SET;
    lock.l_start = (input-1)*sizeof(db);
    lock.l_len = sizeof(db);
    lock.l_pid = getpid();

    lseek(fd, (input-1)*sizeof(db), SEEK_SET);
    read(fd, &db, sizeof(db));

    fcntl(fd, F_SETLKW, &lock);
    printf("Current Counter value : %d \n", db.count);
    db.count++;
    lseek(fd, -1*sizeof(db), SEEK_CUR);
    write(fd, &db, sizeof(db));

    printf("To Unlock, Press Enter\n");
    getchar();
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Done\n");
}

//OUTPUT
// terminal 1:
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 18_record_locking.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// Select Record Number : 2
// Current Counter value : 0 
// To Unlock, Press Enter

// Done

// terminal 2:
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// Select Record Number : 2
// ^C
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// Select Record Number : 1
// Current Counter value : 0 
// To Unlock, Press Enter

// Done

// Done

