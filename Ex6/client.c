#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#define PORT 4771

int main()
{
        int sockfd;
        struct sockaddr_in serv;
        char buff[100];
        
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
        printf("Client Socket with Server Successfully.\n");
        
        strcpy(buff," ");
        printf("\nEnter filename: ");
        fgets(buff,100,stdin);
        write(sockfd,buff,100);
        
        strcpy(buff," ");
        read(sockfd,buff,sizeof(buff));
        printf("Number of words =%s\n",buff);
        close(sockfd);
        return 0;
}
