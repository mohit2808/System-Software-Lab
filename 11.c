/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
 
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[]){         // after running with file 11 push it background and check for the pid and inthat fd and list thereto see if appended or not 
	int fd = open(argv[1], O_RDWR); 

	int fd1 = dup(fd);
	printf("New File Descriptor value via dup = %d\n", fd1);

	int fd2 = dup2(fd, 7);
	printf("New File Descriptor value via dup2 = %d\n", fd2);

	int fd3 = fcntl(fd, F_DUPFD, fd2);
	printf("New File Decriptor value via fcntl = %d\n", fd3);

	getchar();

	return 0; 
}

//OUTPUT
// Terminal 1:
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 11.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out file11 &
// [1] 9159
// mohit@mohit-14IRL8:~/SSHandsOnList1$ New File Descriptor value via dup = 4
// New File Descriptor value via dup2 = 7
// New File Decriptor value via fcntl = 8

// Terminal 2:
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 11.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out file11 &
// [1] 9159
// mohit@mohit-14IRL8:~/SSHandsOnList1$ New File Descriptor value via dup = 4
// New File Descriptor value via dup2 = 7
// New File Decriptor value via fcntl = 8


