#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 4771

void CRC(char data[], char divisor[], char check_value[]){
int N = strlen(divisor);
int l = strlen(data);

    for(int i=0;i<N-1;i++){
        data[l+1] = '0';
    }

    for(int i=0;i<N;i++){
        check_value[i] = data[i];
    }
    do{
        if(check_value[0] == '1'){
            for(int j=0;j<N;j++){
                check_value[j] = ((check_value[j] == divisor[j])?'0':'1');
            }
        }
        for(int j=0;j<N-1;j++){
            check_value[j] = check_value[j+1];
        }
        check_value[j] = data[i++];
    }while(i<=l+N-1);
}
    

int main() {
    char buffer[1024];
    char data[100];
    char divisor[100];
    char check_value[100];

    int sockfd,a,connfd,len;

    struct sockaddr_in servaddr, cliaddr;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1){
        printf("Error Creating Socket\n");
        exit(0);
    }
    printf("Server Socket Created Successfully \n");
    bzero((struct sockaddr*) &servaddr, sizeof(servaddr));

    servaddr.sin.family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0) {
        printf("Error in BIND function");
        exit(0);
    }
    printf("Server Socket Binded \n");
    if((a = listen(sockfd,5)) == -1) {
        printf("Error in LISTEN function");
        exit(0);
    }
    printf("Server Socket Listened...\n");
    len = sizeof(cliaddr);

    if((connfd = accept(sockfd,(struct sockaddr*) &cliaddr,&len))<0) {
        printf("Error in Accept");
        exit(0);
    }

    read(sockfd,buffer,1024);
    sscanf(buffer,"%s\n%s",data,divisor);
    CRC(data,divisor,check_value);
    printf("CRC = %s\n",check_value);

    close(sockfd);
    close(connfd);
    return 0;
}
