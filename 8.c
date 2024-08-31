/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
 
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int f1 = open("file_1", O_RDONLY);
	if(f1<0){
		perror("Status : ");
		exit(0);
	}

	char buffer[1024];
	int size_read;

	while((size_read = read(f1, buffer, sizeof(buffer))) > 0){
		write(1, buffer, size_read);
	}

	close(f1);
	return 0;
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cat file_1
// hello
// this is line 2
// this is line 3
// this is line 4
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 8.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// hello
// this is line 2
// this is line 3
// this is line 4
// mohit@mohit-14IR