/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *3.Write a program to create a file and print the file descriptor value. Use creat ( ) system call
 
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main(){
	
	char filename[30];
	int fd;

	printf("Enter File Name : ");
	scanf("%s", filename);

	fd = creat("filename" , 777);

	perror("There was a Error");
	printf("File Discriptor value of the file is : %d\n", fd);

	int a;
	printf("Enter a Random integer : ");
	scanf("%d", &a);
	close(fd);
		
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 3.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// Enter File Name : filie3
// There was a Error: Success
// File Discriptor value of the file is : 3
// Enter a Random integer : 77

