/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *24. Write a program to create an orphan process.
 
*/

#include<stdio.h>
#include<unistd.h>

int main(){
    if(fork() == 0){
        sleep(4);
        printf("I am an Orphan process");
    }

    else{
        sleep(1); //Here the parent will finish its execution before the child finishes therefore the child becomes orphan.
    }
}

// OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 24.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// mohit@mohit-14IRL8:~/SSHandsOnList1$ I am an Orphan process