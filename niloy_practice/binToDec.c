#include<stdio.h>
#include<math.h>
int main(){
    int bin;
    printf("Enter binary: ");
    scanf("%d",&bin);
    int k=0;
    int dec=0;
    while(bin>0){
        int dig=bin%10;
        dec = dec + dig*(pow(2,k));
        k++;
        bin/10;
    }
    printf("%d ",dec);
    return 0;
}