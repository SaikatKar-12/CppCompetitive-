#include<stdio.h>
#include<malloc.h>
int main(){
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int i=0;i<n-1;i++){
        int min=arr[i];
        int mindx=i;
        for(int j=i;j<n;j++){
            if(min>arr[j]){
                min=arr[j];
                mindx=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[mindx];
        arr[mindx]=temp;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}