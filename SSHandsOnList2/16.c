// Roll Num : MT2024137
// Name : Shah Mohit P
// 16. Write a program to send and receive data from parent to child vice versa. Use two way
// communication.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
    int fd1[2];//Write for parent and read for child
    int fd2[2];//Write for child and read for parent
    char buff1[50], buff2[50];

    pipe(fd1);
    pipe(fd2);

    if(fork() == 0){
        close(fd1[1]);//Closing the write end of parent side
        read(fd1[0], buff2, sizeof(buff2));
        printf("Message From Parent : %s\n", buff2);
        close(fd2[0]);//Closing the read end of parent side
        printf("Enter Message for parent: ");
        scanf(" %[^\n]", buff1);
        write(fd2[1], buff1, sizeof(buff1));
    }

    else{
        close(fd1[0]); //Closing the read end of child
        printf("Enter message for Child: ");
        scanf("%[^\n]", buff2);//This would give a end line at the end
        write(fd1[1], buff2, sizeof(buff2));
        close(fd2[1]); //Closing the write end of child
        read(fd2[0], buff1, sizeof(buff1));
        printf("Message from Parent: %s\n", buff1);
        wait(0);
    }
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 16.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Enter message for Child: Hello from your Father    
// Message From Parent : Hello from your Father
// Enter Message for parent: Hello father
// Message from Parent: Hello father