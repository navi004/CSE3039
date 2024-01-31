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
        char buffer1[100];
        char check_value[100];
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
        strcpy(buffer," ");
        read(connfd,buffer,100);
        printf("Data : %s",buffer);
        read(connfd,buffer1,100);
        printf("Divisor : %s",buffer1);
        
        int n = strlen(buffer1);
        int l = strlen(buffer);
        int k;
        for(int i=0;i<n;i++){
            check_value[i] = buffer[i];
        }
        
        do{
            if(check_value[0]=='1'){
                for(int j=1;j<n;j++){
                    check_value[j] = ((check_value[j] == buffer1[j])?'0':'1');
                }
            }
            
            for(k=0;k<n-1;k++){
                check_value[k] = check_value[k+1];
               
            }
            check_value[k] = buffer[i++];
            
        }while(i<=l+n-1);
        
        printf("%s",check_value);
        write(connfd,check_value,100);
        
        exit(0);
        close(connfd);
          
          return 0;
}
