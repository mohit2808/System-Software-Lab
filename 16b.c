/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 * 16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
*/


#include<stdio.h>
#include<fcntl.h>
#include<sys/file.h>
#include<unistd.h>

int main(int argc, char* argv[]){

        int fd = open(argv[1], O_RDWR);

        struct flock lock;

        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();

        fcntl(fd, F_SETLKW, &lock);

        printf("File Locked\n"); //now if we try to lock the same file from other terminal it will wait for this lock to release. we can do read and write operations but not lock. 
				// But we can apply the read lock for other ternminal. But not the write lock
        getchar();

        lock.l_type = F_UNLCK;

        fcntl(fd, F_SETLK, &lock);

        return 0;
}

/*OUTPUT
 *
 * mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 16b.c
mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out file16b
File Locked

*/
