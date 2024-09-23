// Roll Num : MT2024137
// Name : Shah Mohit P
// 34. Write a program to create a concurrent server.
// a. use fork
// b. use pthread_create
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void *handle_client(void *socket_desc) {
    int new_socket = *(int*)socket_desc;
    free(socket_desc);  // Free the allocated memory for socket
    char buffer[50] = {0};

    int bytes_read = read(new_socket, buffer, 50);
    if (bytes_read > 0) {
        printf("Client: %s\n", buffer);
        send(new_socket, "Message received", strlen("Message received"), 0);
    }
    close(new_socket);  // Close client socket
    pthread_exit(NULL);  // End the thread
}

int main(){

    struct sockaddr_in serv, cli;//Structure in netinet/in.h

    int sd, sz, nsd;
    char buff[50];

    sd = socket(AF_UNIX, SOCK_STREAM, 0); 

    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr = INADDR_ANY; //with INADDR_ANY it can serve any address
    serv.sin_port = htons(5055); //htons converts little endian to big endian type

    bind(sd, (void *)&serv, sizeof(serv));

    listen(sd, 5);//Limit for second argument is from 1 to 5 because at a time 

    sz = sizeof(cli);

    while(1){

        nsd = accept(sd, (void*)(&cli), &sz);
        pthread_t thread_id;
        int *new_sock = malloc(sizeof(int));
        *new_sock = nsd;

        if (pthread_create(&thread_id, NULL, handle_client, (void*)new_sock) != 0) {
            perror("Thread creation failed");
            free(new_sock);
            close(nsd);
        }

        pthread_detach(thread_id);
    }
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