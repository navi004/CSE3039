#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#define PORT 4771
int main(int argc,char *argv[])
{
        int sockfd;
        struct sockaddr_in serv;
        char buffer[100];
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        printf("Client Socket Created Successfully.\n");
        memset(&serv,0,sizeof(serv));
        serv.sin_family=AF_INET;
        serv.sin_port=htons(PORT);
        serv.sin_addr.s_addr=INADDR_ANY;
        if (connect(sockfd,(struct sockaddr *)&serv, sizeof(serv))<0)
        {
                printf("error in connect");
                exit(0);
        }
        int n;
        printf("Enter the number of bits: ");
        scanf("%d",&n);
        char data[n];
        printf("Enter the data:");
        scanf("%s",data);
        
        write(sockfd,data,strlen(data)+1);
        read(sockfd,buffer,sizeof(buffer));
        
        printf("CodeWord:");
        for(int i=0;buffer[i]!='\0';i++){
                printf("%c ",buffer[i]);                                                                    
        }
        
        close(sockfd);
        return 0;
}
