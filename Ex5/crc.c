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


int main(int argc,char *argv[]) {
        int sockfd;
        struct sockaddr_in serv;
        char buffer[100];
        char buffer1[100];
        char recv[100];
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
        
        strcpy(buffer," ");
        printf("Data : ");
        fgets(buffer,100,stdin);
        
        int n = strlen(buffer1);
        int l = strlen(buffer);
        
        for(int i=l;i<l+n-1;i++) {
            buffer[i] = '0';
        }
        
        write(sockfd,buffer,100);
        
        strcpy(buffer1," ");
        printf("Divisor : ");
        fgets(buffer1,100,stdin);
        write(sockfd,buffer1,100);
        
        
        strcpy(recv," ");
        read(sockfd,recv,sizeof(recv));
        
        for(int i=l;i<l+n-1;i++){
            buffer[i] = recv[i-l];
        }
        printf("CodeWord : %s",recv);
        

        exit(0);
        close(sockfd);
          
        return 0 ;
}
