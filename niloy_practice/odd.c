#include<stdio.h>
int main(){
    // for(int i=0;i<50;i++){
    //     if(i%2==0){
    //         printf("%d ",i);
    //     }else continue;
    // }
    int i=0;
    while(i<51){
        if(i%2==0){
            printf("%d ",i);
        }
        i++;
    }
    return 0;
}