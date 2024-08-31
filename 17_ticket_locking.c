/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
 
*/

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    struct{
        int ticket_no;
    }db;

    struct flock lock;

    int fd = open("db", O_RDWR);

    read(fd, &db, sizeof(db));
    
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    fcntl(fd, F_SETLKW, &lock);//Locking fd with the lock having above properties

    printf("Current Ticket Number : %d\n", db.ticket_no);

    db.ticket_no++;
    lseek(fd, 0L, SEEK_SET);// Getting the cursor to the start of the file which moved at last because of the previous read

    printf("Enter to unlock\n");
    write(fd, &db, sizeof(db));
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Unlocked\n");

    return 0;
}

//OUTPUT
// First Terminal:
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 17_ticket_locking.c 
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// Current Ticket Number : 3
// Enter to unlock

// Unlocked

// Second Terminal:
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// Current Ticket Number : 4
// Enter to unlock

// Unlocked

