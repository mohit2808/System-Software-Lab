/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *5. Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
 
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main(){
	int fd1, fd2, fd3, fd4, fd5;

	open("f1.c", O_RDWR);
	open("f2.c", O_RDWR);
	open("f3.c", O_RDWR);
	open("f4.c", O_RDWR);
	open("f5.c", O_RDWR);
	
	perror("Status : ");
	getchar();
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 5.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out &
// [2] 11556
// mohit@mohit-14IRL8:~/SSHandsOnList1$ Status : : Success


// Terminal 2:
// mohit@mohit-14IRL8:~$ ll /proc/11556/fd
// total 0
// dr-x------ 2 mohit mohit  8 Aug 31 23:46 ./
// dr-xr-xr-x 9 mohit mohit  0 Aug 31 23:46 ../
// lrwx------ 1 mohit mohit 64 Aug 31 23:46 0 -> /dev/pts/2
// lrwx------ 1 mohit mohit 64 Aug 31 23:46 1 -> /dev/pts/2
// lrwx------ 1 mohit mohit 64 Aug 31 23:46 2 -> /dev/pts/2
// lrwx------ 1 mohit mohit 64 Aug 31 23:46 3 -> /home/mohit/SSHandsOnList1/f1.c
// lrwx------ 1 mohit mohit 64 Aug 31 23:46 4 -> /home/mohit/SSHandsOnList1/f2.c
// lrwx------ 1 mohit mohit 64 Aug 31 23:46 5 -> /home/mohit/SSHandsOnList1/f3.c
// lrwx------ 1 mohit mohit 64 Aug 31 23:46 6 -> /home/mohit/SSHandsOnList1/f4.c
// lrwx------ 1 mohit mohit 64 Aug 31 23:46 7 -> /home/mohit/SSHandsOnList1/f5.c
