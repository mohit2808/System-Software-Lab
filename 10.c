/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
 
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char* argv[]){
	
	int fd = open(argv[1], O_RDWR, 0777);
	if(fd < 0){
		perror("Status :");
		return 0;
	}

	int sz = write(fd, "Hello Hiii", strlen("Hello Hiii"));
	
	int offset = lseek(fd, 10, SEEK_SET);

	printf("%d\n", offset);

	write(fd, "More Bytes", strlen("More Bytes"));

	return 0;
}	

//OUTput
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cat file10
// Hello HiiiMore Bytesmohit@mohit-14IRL8:~/SSHandsOnList1$ od -b file10
// 0000000 110 145 154 154 157 040 110 151 151 151 115 157 162 145 040 102
// 0000020 171 164 145 163
// 0000024


