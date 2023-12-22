#include<stdio.h>
int partition(int arr[],int si,int ei){
    int pivot=arr[si];
    int count=0;
    for(int i=si+1;i<=ei;i++){
        if(arr[i]<pivot) count++;
    }
    int pivotidx=count+si;
    int temp=arr[pivotidx];
    arr[pivotidx]=arr[si];
    arr[si]=temp;
    int i=si;
    int j=ei;
    while(i<pivotidx && j>pivotidx){
        if(arr[i]<pivot) i++;
        else if(arr[j]>pivot) j--;
        else if(arr[i]>pivot && arr[j]<pivot){
            temp= arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    return pivotidx;
}
void quicksort(int arr[],int si,int ei){
    if(si>=ei) return;
    int pi=partition(arr,si,ei);
    quicksort(arr,si,pi-1);
    quicksort(arr,pi+1,ei);
}
int main(){
    int a[]={5,2,1,4,3};
    int n=5;
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}