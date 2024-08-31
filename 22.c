/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
 
*/


#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    int fd = open("file22", O_RDWR, 0777);

    //char buffer[1024];

    if(fork() == 0){;
        char text[] = "This is child\n";
        write(fd, text, sizeof(text)-1);
    }

    else{
        char text[] = "This is Parent\n";
        write(fd, text, sizeof(text)-1);
    }
}

//OUTPUT

// mohit@mohit-14IRL8:~/SSHandsOnList1$ touch file22
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 22.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cat file22
// This is Parent
// This is child
