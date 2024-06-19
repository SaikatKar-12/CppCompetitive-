#include<stdio.h>
int main(){
    int n=1;
    int sum=0;
    int i=0;
    while(n!=0){
        
        scanf("%d",&n);
        if(n>0){
            sum=sum+n;
            i++;
        }
    }
    int avg=sum/i;
    printf("sum=%d avg= %d",sum,avg);
}