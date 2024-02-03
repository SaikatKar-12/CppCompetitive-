#include<stdio.h>
#include<stdlib.h>
#define size 100
void merge(int arr[],int si,int mid,int ei){
    int i=si;
    int j=mid+1;
    int k=si;
    int temp[size];
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
        }else if(arr[i]>arr[j]){
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=ei){
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(int x=si;x<k;x++){
        arr[x]=temp[x];
    }
}
void mergesort(int arr[],int si,int ei){
    if(si>=ei) return;
    int mid=(ei+si)/2;
    mergesort(arr,si,mid);
    mergesort(arr,mid+1,ei);

    merge(arr,si,mid,ei);
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7,2,8,1,3,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergesort(arr,0,n-1);

    printf("Sorted array is \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}