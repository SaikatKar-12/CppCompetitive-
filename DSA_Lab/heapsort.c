#include<stdio.h>
#define size 100
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void downHeapify(int hp[],int idx,int n){
    while(idx<n){
            int lc=2*idx+1;
            int rc=2*idx+2;
            if(lc>=n) break;
            int maxEl=idx;
            if(hp[lc]>hp[maxEl]) maxEl=lc;
            if(rc<n && hp[rc]>hp[maxEl]) maxEl=rc;
            if(maxEl!=idx){
                swap(&hp[maxEl],&hp[idx]);
                idx=maxEl;
            }else break;
        }
}
void heapsort(int arr[],int n){
    for(int i=n/2;i>=0;i--){
        downHeapify(arr,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        downHeapify(arr,0,i);
    }
}
int main(){
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[size];
    printf("input data:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}