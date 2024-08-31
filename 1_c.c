/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call) 
*/


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	
	int fd;
	char filename[30];

	printf("Enter the FIle name");
	scanf("%s", filename);

	mkfifo(filename, 0777);

	return 0;
}

/*OUTPUT
 *
 * mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 1_c.c
mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
Enter the FIle namefifotest
mohit@mohit-14IRL8:~/SSHandsOnList1$ echo"Trying to push in fifotest file" >> fifotest

	Waiting for the fifo file to be read in another terminal
*/
