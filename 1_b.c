/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call) 
*/


#include<stdio.h>
#include<unistd.h>

void main(void){
	
	char target[30];
	char hrdlnk[30];

	printf("Enter the Target file name : ");
	scanf("%s", target);
	printf("Enter the file name which is to be hard linked : ");
	scanf("%s", hrdlnk);

	link(target, hrdlnk);
}


/*OUTPUT
 *
 * mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
Enter the Target file name : file1
Enter the file name which is to be hard linked : hardlink

*/
