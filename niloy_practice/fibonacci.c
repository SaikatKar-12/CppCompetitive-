#include<stdio.h>
int main()
{
    int a=0;
    int b=1;
    printf ("%d",a);
    printf("%d",b);
    for (int i=0;i<10;i++){
        int fb=a+b;
        printf ("%d ", fb);
         a=b;
         b=fb;
    }
}