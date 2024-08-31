/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
 
*/


#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc,char* argv[]) //Provide File name as command line argument
{
	struct stat info;
	
	if(stat(argv[1],&info)==-1)
	{
		printf("stat error/n");
		exit(0);
	}
	printf("inode number=%ld\n",info.st_ino);
	printf("No of Hardlink = %ld\n",info.st_nlink);
	printf("uid = %d\n", info.st_uid);
	printf("gid = %d\n", info.st_gid);
	printf("Size = %ld\n",(long)info.st_size);
	printf("Number of blocks = %ld\n", info.st_blocks);
	printf("Last file access = %s",ctime(&info.st_atime));
	printf("Notification time = %s",ctime(&info.st_mtime));
	printf("Last Change Time = %s", ctime(&info.st_ctime));

	return 0;
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 9.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out file1
// inode number=2630560
// No of Hardlink = 2
// uid = 1000
// gid = 1000
// Size = 31
// Number of blocks = 8
// Last file access = Thu Aug 29 23:49:06 2024
// Notification time = Thu Aug 22 09:14:43 2024
// Last Change Time = Thu Aug 29 09:17:59 2024
