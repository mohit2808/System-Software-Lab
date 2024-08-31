/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *23. Write a program to create a Zombie state of the running program.
 
*/

#include<stdio.h>
#include<unistd.h>

int main(){

    if(fork() == 0){
        printf("This is a child Process\n");
    }

    else
        getchar(); //here parent would be waiting for the character but the child has already been executed and the parent would not know about it therefore the child becomes zombie.
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 23.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// This is a child Process

