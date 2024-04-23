#include<stdio.h>
int main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int nsp=n-1;
    int nst=1;
    for(int i=1;i<=2*n-1;i++){
       for(int j=1;j<=nsp;j++){
        printf(" ");
       }
       if(i<=n-1) nsp--;
       else nsp++;
       for(int k=1;k<=nst;k++){
        printf("*");
       }
       if(i<=n-1) nst=nst+2;
       else nst=nst-2;
       printf("\n");
    }

    return 0;
}