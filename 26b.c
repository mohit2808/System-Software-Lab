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
    char *str[] = {"./file26b", "Got INput", "Hello this is Program 26b", NULL};

    if(execvp("./file26b", str) == -1){
        perror("Status : ");
    }
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc file26b.c -o file26b
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 26b.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out hii hello
// Got INput, Hello this is Program 26b


