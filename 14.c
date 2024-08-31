/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 * 14.Write a program to find the type of a file.
      a. Input should be taken from command line.
      b. program should be able to identify any type of a file. 
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
        struct stat info; // stat is a structure

        if(lstat(argv[1],&info)==-1) // lstat is a system call
        {
                printf("stat error/n");
                exit(0);
	}

	printf("File type: ");

           switch (info.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }

	   return 0;

}


/* OUTPUT
mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 14.c
mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out fifofile1
File type: FIFO/pipe

*/
