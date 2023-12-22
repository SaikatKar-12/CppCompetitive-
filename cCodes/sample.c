#include<stdio.h>
#include<string.h>
void merge(int a[],int lo,int hi,int mid){
    int i,j,k,b[100];
    i=lo;
    j=mid+1;
    k=lo;
    while(i<=mid && j<=hi){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
            k++;
        }else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=hi){
        b[k]=a[j];
        j++;
        k++;
    }
    for(int i=lo;i<=hi;i++){
        a[i]=b[i];
    }
}
void mergesort(int a[],int lo,int hi){
    int mid;
    if(lo<hi){
        mid=(hi+lo)/2;
        mergesort(a,lo,mid);
        mergesort(a,mid+1,hi);
        merge(a,lo,hi,mid);
    }
}
int main(){
    int a[]={5,2,1,4,3};
    int n=5;
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}