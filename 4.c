/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
 
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main(){
	
	char filename[30];
	int fd;

	printf("Enter the Filename : ");
	scanf("%s", filename);

	fd = open(filename, O_RDWR, 777);

	perror("Status : ");

	printf("IF we add O_CREAT | O_EXCL in the flag of open then we will get error if the file already existed\n");

	printf("File Descriptor value for the file is : %d\n", fd);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 4.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// Enter the Filename : file4
// Status : : No such file or directory
// IF we add O_CREAT | O_EXCL in the flag of open then we will get error if the file already existed
// File Descriptor value for the file is : -1
// mohit@mohit-14IRL8:~/SSHandsOnList1$ touch file4
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 4.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// Enter the Filename : file4
// Status : : Success
// IF we add O_CREAT | O_EXCL in the flag of open then we will get error if the file already existed
// File Descriptor value for the file is : 3
