//TCP CLIENT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 4771

int main() {
        
        int n;
        char data[100];
        int sockfd;
        struct sockaddr_in serv;
        char buffer[100];
        sockfd = socket(AF_INET,SOCK_STREAM,0);
        
        printf("Client Socket Created Successfully.\n");
        memset(&serv,0,sizeof(serv));
        serv.sin_family = AF_INET;
        serv.sin_port = htons(PORT);
        serv.sin_addr.s_addr = INADDR_ANY;
        
        if(connect(sockfd,(struct sockaddr*) &serv,sizeof(serv)) < 0) {
                printf("Error in Connect");
                exit(0);
        }
        printf("Client Socket with Server Successfully.\n");
        
        printf("Enter the No of the bits in data(n) = ");
        scanf("%d",&n);
        printf("Enter the data = ");
        scanf("%s",data);
        
        write(sockfd,data,100);
        
        read(sockfd,buffer,sizeof(buffer));
        printf("No of Redundant Bits = %s",buffer);
        
        
        close(sockfd);
          
        return 0 ;
}
