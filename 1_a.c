/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call) 
*/

#include <stdio.h>
#include <unistd.h>

void main(void){
	char target[30];
	char sftlnk[30];

	printf("Enter Target File Name : ");
	scanf("%s",target);
	printf("Enter Soft Link File Name : ");
	scanf("%s",sftlnk);

	//FILE *tarptr = fopen(target, "w");
	//FILE *sftptr = fopen(sftlnk, "w");

	symlink(target, sftlnk);
	
	perror("System says : ");	
}


/*OUTPUT
 *
 * Enter Target File Name : file1
Enter Soft Link File Name : softlink3
System says : : Success

*/
