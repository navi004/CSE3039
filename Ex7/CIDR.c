#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

void cal_CIDR(char ipAddress[],int mask){
    struct in_addr addr,firstAddress,lastAddress;
    inet_aton(ipAddress,&addr);
    uint32_t ip = ntohl(addr.s_addr);
    uint32_t network = (ip & (0xFFFFFFFF << (32-mask)));
    uint32_t broadcast = network + (0xFFFFFFFF >> mask);

    firstAddress.s_addr = htonl(network);
    lastAddress.s_addr = htonl(broadcast);
    printf("Given IP Address: %s\n",ipAddress);
    printf("Mask Value:/%d\n",mask);
    printf("First Address:%s\n",inet_ntoa(firstAddress));
    printf("Last Address:%s\n",inet_ntoa(lastAddress));
}

int main(){
    char ipAddress[16];
    int num,mask;
    printf("Enter the IP Address:");
    scanf("%s",ipAddress);
    printf("Enter an optin:\n1.ClassFull\n2.Classless\n");
    int flag;
    scanf("%d",&flag);

    switch(flag){
        case 1:
            num = atoi(ipAddress);
            if(num >= 1 && num <= 127){
                printf("Class A\n");
                mask = 8;
            }
            else if(num>=128 && num <= 191){
                printf("Class B\n");
                mask = 16;
            }
            else if(num>=192 && num <= 223){
                printf("Class C\n");
                mask = 24;
            }
            else if(num >= 224 && num <= 239){
                printf("Class D\n");
                printf("CIDR cannot be calculated\n");
                return 1;
            }
            else{
                printf("Class E\n");
                printf("CIDR cannot be calculated\n");
                return 1;
            }
            cal_CIDR(ipAddress,mask);
            break;
        case 2:
            printf("Enter the mask value :");
            scanf("%d",&mask);
            cal_CIDR(ipAddress, mask);
            break;
    }
    printf("No of hosts = 2^%d\n",32-mask);
    return 0;
}
