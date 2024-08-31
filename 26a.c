/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
extern char **environ;

int main(){
    int exe = execl("file26a", "./file26a", (char *)NULL);
    if(exe = -1){
        perror("Status : ");
        return 1;
    }
}
// OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc file26a.c -o file26a
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 26a.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// file26a executable is executed

