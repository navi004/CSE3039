#include <stdio.h>

int main(){
    printf("Enter the IP : ");
    char ip[15];
    scanf("%s",ip);
    
    printf("Enter the Choice(Classful - 0/Classless - 1) : ");
    int flag;
    scanf("%d",&flag);
    
    int len = 0;
    for(int i=0;ip[i]!= '\0';i++){
        len++;
    }
    
    char parts_nums[3];
    int s = 0;
    int k=0;
    int count = 0;
    for(int i=0;ip[i]!='\0';i++){
        count++;
        if(ip[i] == '.'){
            parts_nums[k] = count-1;
            count = 0;
            k++;
        }
        parts_nums[3] = count;
    }
    char values[3][2];
    for(int i=0;i<len;i++){
        values[i]  = ip[]
    }

    if(flag  == 1){
        printf("Enter the mask value : ");
        int mask;
        scanf("%d",&mask);
    }
    printf("\n");
    for(int i=0;i<4;i++){
        printf("%d ",parts[i]);
    }    
    printf("\n");
            
}
