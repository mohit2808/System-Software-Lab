/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *21. Write a program, call fork and print the parent and child process id.
 
*/


#include<stdio.h>
#include<unistd.h>

int main(){
    int child = fork();

    if(child == -1) printf("Child Not Created\n");

    else if(child == 0) printf("Process Id of Child is : %d\n", getpid()); //For the parent process we could have also used getppid() in this line

    else printf("Parent pid : %d\n",getpid());

}

// OUTPUT

// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 21.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// Parent pid : 74398
// Process Id of Child is : 74399
