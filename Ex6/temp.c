#include <stdio.h>
#include <math.h>

void cal_Rs(int n,int data[],int r,int R[],int codeWord[]){
    int pos[r];
    for(int i=0;i<r;i++){
        pos[i] = (int)pow(2,i);
    }

    int l = n+r;
    int d = 0;
    do{
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                if(i == (int)pow(2,j)){
                    codeWord[j] = R[j++];
                }
            }
        
            codeWord[i] = data[d++];
        }
    }while(d<n);
}

int main(){
    int n = 7;
    int data[7] = {1,0,0,1,1,1,0};
    int r = 4;
    int R[4] = {1,0,0,1};
    int codeWord[11];
    
    cal_Rs(n,data,r,R,codeWord);
    for(int i=0;i<11;i++){
        printf("%d",codeWord[i]);
    }
}
