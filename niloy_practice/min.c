#include<stdio.h>
int main(){
    int n;
    int min=99999999;
    printf("Enter no:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        if(num<min){
            min=num;
        }
    }
    printf("min: %d",min);
    return 0;
}