// Roll Num : MT2024137
// Name : Shah Mohit P
// 34. Write a program to create a concurrent server.
// a. use fork
// b. use pthread_create
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){
    struct sockaddr_in serv;

    int sd;
    char buff[50];
    sd = socket(AF_UNIX, SOCK_STREAM, 0);

    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5055);

    connect(sd, (void*) (&serv), sizeof(serv));
    write(sd, "Hello Server\n", 14);
    read(sd, buff, sizeof(buff));
    printf("Message from Server: %s\n", buff);

}

//OUTPUT
// Terminal 1:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 34bServer.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Message from Client: Hello Server

// Message from Client: Hello Server

// Message from Client: Hello Server

// Message from Client: Hello Server

// Message from Client: Hello Server

// Message from Client: Hello Server

// Terminal 2:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 34bClient.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Message from Server: ACK from Server