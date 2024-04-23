#include<stdio.h>
int main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int nsp=1;
    int nst=1;
    for(int i=1;i<=2*n+1;i++){
        printf("*");
    }
    printf("\n");
    for(int i=1;i<=n;i++){
       for(int j=0;j<=n-i;j++){
        printf("*");
       }
       for(int k=1;k<=nsp;k++){
        printf(" ");
       }
       nsp+=2;
        for(int l=0;l<=n-i;l++){
        printf("*");
       }
       printf("\n");
    }

    return 0;
}