/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *12. Write a program to find out the opening mode of a file. Use fcntl.
 
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[]){
	
	int fd = open(argv[1], O_RDWR);

	int md = fcntl(fd, F_GETFL);

	printf("Access Mode of the file is : %d\n", md);

	return 0;
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 12.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out file11
// Access Mode of the file is : 32770
