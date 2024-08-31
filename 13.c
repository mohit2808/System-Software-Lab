/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
 
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/select.h>
#include<sys/time.h>

int main(){

	fd_set rd; //this is a structure
	struct timeval tv;
	FD_ZERO(&rd);  //Clearing the fdSet before initializing
	FD_SET(0, &rd);  // Assigning the fd of stdin to the fd set

	tv.tv_sec = 10; // Seconds
	tv.tv_usec = 0; // Microseconds

	int sl = select(1, &rd, NULL, NULL, &tv);

	if(sl == 0) printf("TimeOut\n");  //Wait time crosses 10 secs

	else if(sl == -1) printf("Failure\n"); // Failed to select

	else printf("Input Taken\n");  // Sucess

	return 0;
}

/* OUTPUT
 
Sucess:
mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 13.c
mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
hello
Input Taken

Timeout:
mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 13.c
mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
TimeOut

 
 
*/ 
