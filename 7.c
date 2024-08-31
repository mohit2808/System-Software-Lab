/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *7. Write a program to copy file1 into file2 ($cp file1 file2).
 
*/


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int f1 = open(argv[1], O_RDONLY);
	if(f1<0){
		perror("Status : ");
		return 0;
	}

	int f2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0600);
	if(f2<0){
                perror("Status : ");
                return 0;
        }

	char buffer[1000];

	int read_size;

	while((read_size = read(f1, buffer, sizeof(buffer))) > 0){
		write(f2, buffer, read_size);
	}

	return 0;

}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 7.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out file7a file7b
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cat file7a
// HEllo This is a filemohit@mohit-14IRL8:~/SSHandsOnList1$ cat file7b
// HEllo This is a filemohit@mohit-14IRL8:~/SSHandsOnList1$ 