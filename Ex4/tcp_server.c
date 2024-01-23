//TCP CHAT SERVER

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 4771

int main() {
        char buffer[100];
        int sockfd, a,connfd,len,i=0;
        
        struct sockaddr_in servaddr, cliaddr;
        sockfd = socket(AF_INET,SOCK_STREAM,0);
        if(sockfd == -1){
              printf("Error creating socket\n");
              exit(0);
        }
        printf("Server Socket Created Successfully \n");
        bzero((struct sockaddr*) &servaddr,sizeof(servaddr));
        
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(PORT);
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        
        if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0) {
                printf("Error in BIND function");
                exit(0);
        }
        printf("Server Socket Binded \n");
        if((a = listen(sockfd,5)) == -1) {
                printf("Error in LISTEN function");
                exit(0);
        }
        printf("Server Socket Listened....\n");
        len = sizeof(cliaddr);
        
        if((connfd = accept(sockfd,(struct sockaddr*) &cliaddr,&len)) < 0){
                printf("Error in Accept");
                exit(0);
        }
        do
        {
                strcpy(buffer," ");
                read(connfd,buffer,100);
                printf("From client: %s",buffer);
                if(strcmp(buffer,"bye\n") == 0) {
                        printf("From Client:%s",buffer);
                        goto stop;
                }
                printf("Server : ");
                fgets(buffer, sizeof(buffer),stdin);
                write(connfd,buffer,100);
          }
          while(strcmp(buffer,"bye\n") != 0);
          stop:
          exit(0);
          close(connfd);
          
          return 0;
}
