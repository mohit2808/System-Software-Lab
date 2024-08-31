/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
 
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main(){
	 
	int fd;
	ssize_t nr;
	char buffer[30];
	//unsigned long word;

	//fd = open("testfile", O_RDWR);
	
	nr = read(0 , buffer, 30);
	
	write(1, buffer, sizeof(nr));

	perror("Status : ");

	printf("%ld\n", nr);	
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 6.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// hello
// hello
// Status : : Success
// 6


