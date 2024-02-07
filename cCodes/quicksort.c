#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int si,int ei){
    int pivotEle=arr[(si+ei)/2];
    int count=0;
    for(int i=si;i<=ei;i++){
        if(i==(si+ei)/2) continue;
        if(arr[i]<=pivotEle) count++;
    }
    int pi=count+si;
    swap(&arr[(si+ei)/2],&arr[pi]);
    int i=si;
    int j=ei;
    //printf("%d ",arr[pi]);
    while(i<pi && j>pi){
        if(arr[i]<=pivotEle) i++;
        if(arr[j]>pivotEle) j--;
        if(arr[i]>pivotEle && arr[j]<=pivotEle){
            swap(&arr[i],&arr[j]);
            i++;
            j--;
        }
    }
    return pi;
}

void quicksort(int arr[],int si,int ei){
    if(si>=ei) return;

    int pi=partition(arr,si,ei);

    quicksort(arr,si,pi-1);
    quicksort(arr,pi+1,ei);
}
int main(){
    int a[]={5,6,2,1,4,3,8,7,-2};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    quicksort(a,0,n-1);
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}